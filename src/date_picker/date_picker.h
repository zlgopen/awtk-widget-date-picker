/**
 * File:   date_picker.h
 * Author: AWTK Develop Team
 * Brief:  日期选择控件。
 *
 * Copyright (c) 2020 - 2020 Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2020-07-12 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_DATE_PICKER_H
#define TK_DATE_PICKER_H

#include "base/widget.h"

BEGIN_C_DECLS
/**
 * @class date_picker_t
 * @parent widget_t
 * @annotation ["scriptable","design","widget"]
 * 日期选择控件。
 */
typedef struct _date_picker_t {
  widget_t widget;

  /**
   * @property {uint32_t} year
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 年。
   */
  uint32_t year;

  /**
   * @property {uint32_t} month
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 月。
   */
  uint32_t month;

  /**
   * @property {uint32_t} day
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 日。
   */
  uint32_t day;

  /*private*/
  bool_t inited;
} date_picker_t;

/**
 * @event {event_t} EVT_VALUE_CHANGED
 * 值改变事件。
 */

/**
 * @method date_picker_create
 * @annotation ["constructor", "scriptable"]
 * 创建date_picker对象
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} date_picker对象。
 */
widget_t* date_picker_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method date_picker_cast
 * 转换为date_picker对象(供脚本语言使用)。
 * @annotation ["cast", "scriptable"]
 * @param {widget_t*} widget date_picker对象。
 *
 * @return {widget_t*} date_picker对象。
 */
widget_t* date_picker_cast(widget_t* widget);

/**
 * @method date_picker_set_year
 * 设置 年。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint32_t} year 年。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t date_picker_set_year(widget_t* widget, uint32_t year);

/**
 * @method date_picker_set_month
 * 设置 月。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint32_t} month 月。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t date_picker_set_month(widget_t* widget, uint32_t month);

/**
 * @method date_picker_set_day
 * 设置 日。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget widget对象。
 * @param {uint32_t} day 日。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t date_picker_set_day(widget_t* widget, uint32_t day);

#define DATE_PICKER_PROP_YEAR "year"
#define DATE_PICKER_PROP_MONTH "month"
#define DATE_PICKER_PROP_DAY "day"

#define WIDGET_TYPE_DATE_PICKER "date_picker"

#define DATE_PICKER(widget) ((date_picker_t*)(date_picker_cast(WIDGET(widget))))

/*public for subclass and runtime type check*/
TK_EXTERN_VTABLE(date_picker);

END_C_DECLS

#endif /*TK_DATE_PICKER_H*/
