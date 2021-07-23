#include "d_engine.h"

DEngine::DEngine()
{
  must_init(al_init(), "allegro");
  must_init(al_install_keyboard(), "keyboard");

  this->timer = al_create_timer(1.0 / 30.0);
  must_init(timer, "timer");

  this->queue = al_create_event_queue();
  must_init(queue, "queue");

  this->font = al_create_builtin_font();
  must_init(font, "font");

  must_init(al_init_primitives_addon(), "primitives");

  must_init(al_init_image_addon(), "image_addon");
}

DEngine::~DEngine()
{
  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
}

void DEngine::run()
{
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(disp));
  al_register_event_source(queue, al_get_timer_event_source(timer));

  bool done = false;
  bool redraw = true;

  al_start_timer(timer);
  while (1)
  {
    al_wait_for_event(queue, &event);

    switch (event.type)
    {
    case ALLEGRO_EVENT_TIMER:
      // game logic goes here.
      redraw = true;
      break;

    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      done = true;
      break;
    }

    if (done)
      break;

    if (redraw && al_is_event_queue_empty(queue))
    {
      al_clear_to_color(al_map_rgb(0, 0, 0));

      std::vector<GameObject *> objects = this->scenes[0]->get_objects();
      for (int i = 0; i < objects.size(); i += 1)
      {
        std::vector<Sprite *> components = objects[i]->get_components<Sprite>();
        for (int j = 0; i < components.size(); i += 1)
        {
          components[j]->render();
        }
      }

      al_flip_display();
      redraw = false;
    }
  }
}

void DEngine::set_resolution(int x, int y)
{
  this->disp = al_create_display(x, y);
  this->must_init(disp, "display");

  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
}

void DEngine::must_init(bool test, const char *description)
{
  if (test)
    return;

  std::cout << "couldn't initialize" << description << std::endl;
}

void DEngine::add_scene(Scene* scene)
{
  this->scenes.push_back(scene);
}