#include "myobject2.h"

typedef struct
{
    char *filename;

} MyObject2Private;

G_DEFINE_TYPE_WITH_PRIVATE(MyObject2, my_object2, G_TYPE_OBJECT)

static void my_object2_init(MyObject2 *self)
{
    g_print("%s\n", "my_object2_init");

    MyObject2Private *priv = my_object2_get_instance_private(self);
}

static void my_object2_class_init(MyObject2Class *klass)
{
    g_print("%s\n", "my_object2_class_init");
}