#ifndef __my_object2_h__
#define __my_obkect2_h__

#include <glib-object.h>

G_BEGIN_DECLS

#define MY_TYPE_OBJECT2 my_object2_get_type()
G_DECLARE_DERIVABLE_TYPE(MyObject2, my_object2, MY, OBJECT2, GObject)

struct _MyObject2Class
{
    GObjectClass parent_class;
    gpointer padding[12];
};

G_END_DECLS

#endif