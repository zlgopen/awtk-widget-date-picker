#include "awtk.h"

static ret_t on_close(void* ctx, event_t* e) {
  tk_quit();

  return RET_OK;
}

static ret_t on_lang_changed(void* ctx, event_t* e) {
  widget_t* combo_box = WIDGET(e->target);
  char country[3];
  char language[3];
  const char* str = combo_box_get_text(combo_box);

  tk_strncpy(language, str, 2);
  tk_strncpy(country, str + 3, 2);
  locale_info_change(locale_info(), language, country);

  return RET_OK;
}

/**
 * 初始化
 */
ret_t application_init(void) {
  date_picker_register();

  widget_t* win = window_open("main");
  widget_child_on(win, "close", EVT_CLICK, on_close, NULL); 
  widget_child_on(win, "lang", EVT_VALUE_CHANGED, on_lang_changed, NULL); 

  return RET_OK;
}

/**
 * 退出
 */
ret_t application_exit(void) {
  log_debug("application_exit\n");
  return RET_OK;
}
