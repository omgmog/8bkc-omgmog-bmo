#include "8bkc-hal.h"      // kchalinit, etc. includes nvs functions
#include "powerbtn_menu.h" // Power Button menu stuff powerbtn_menu_show, constants, etc
#include "tilegfx.h"       // tilegfx functions and types

#include "graphics.h" // Tile data

//Menu options: first one is start, second one is exit.
#define MENU_OPT_START 0
#define MENU_OPT_EXIT 1

void render_sprite() {
  tilegfx_tile_map_render(&map_sprite_sprite, 0, 0, NULL);
}

static void do_powerbtn_menu() {
  int i=powerbtn_menu_show(tilegfx_get_fb());
  if (i==POWERBTN_MENU_EXIT) kchal_exit_to_chooser();
  if (i==POWERBTN_MENU_POWERDOWN) kchal_power_down();
}

int get_keydown() {
  static int oldBtns=0xffff;
  int newBtns=kchal_get_keys();
  int ret=(oldBtns^newBtns)&newBtns;
  oldBtns=newBtns;
  return ret;
}

int do_menu() {
  while (1) {
    render_sprite();

    //Flush display.
    tilegfx_flush();

    int btn = get_keydown();
    if (btn&KC_BTN_POWER) do_powerbtn_menu();
  }
}

void app_main() {
  kchal_init();
  tilegfx_init(0, 50); //Initialize TileGFX @ 50FPS -- gotta get them FPS!


  while (1) {
    int r = do_menu();

    if (r == MENU_OPT_START) {
      // stub.
    } else {
      kchal_exit_to_chooser();
    }
  }

}
