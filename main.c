#include "myobject1.h"
#include "myobject2.h"

int main(int argc, char *argv[])
{
    MyObject1 *object1 = g_object_new(MY_TYPE_OBJECT1, NULL);

    GValue val = G_VALUE_INIT;
    g_value_init(&val, G_TYPE_UINT);
    g_value_set_uint(&val, 2);

    g_object_set_property(G_OBJECT(object1), "zoom-level", &val);

    MyObject2 *object2 = g_object_new(MY_TYPE_OBJECT2, NULL);
}
