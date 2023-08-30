#ifndef __my_object1_h__
#define __my_obkect1_h__

#include <glib-object.h>

G_BEGIN_DECLS

#define MY_TYPE_OBJECT1 my_object1_get_type()
G_DECLARE_FINAL_TYPE(MyObject1, my_object1, MY, OBJECT1, GObject)

G_END_DECLS

#endif