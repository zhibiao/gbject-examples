#include "myobject1.h"

struct _MyObject1
{
    GObject parent_instance;
    char *filename;
    guint zoom_level;
};

G_DEFINE_TYPE(MyObject1, my_object1, G_TYPE_OBJECT)

enum
{
    PROP_FILENAME = 1,
    PROP_ZOOM_LEVEL,
    N_PROPERTIES
};

static GParamSpec *obj_properties[N_PROPERTIES] = {
    NULL,
};

void my_object1_set_property(GObject *object,
                             guint property_id,
                             const GValue *value,
                             GParamSpec *pspec)
{
    g_print("my_object1_set_property:%d \n", property_id);

    MyObject1 *self = MY_OBJECT1(object);

    switch (property_id)
    {
    case PROP_FILENAME:
        g_value_set_string(value, self->filename);
        break;

    case PROP_ZOOM_LEVEL:
        g_value_set_uint(value, self->zoom_level);
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        break;
    }
}

void my_object1_get_property(GObject *object,
                             guint property_id,
                             GValue *value,
                             GParamSpec *pspec)
{
    g_print("my_object1_get_property:%d \n", property_id);

    MyObject1 *self = MY_OBJECT1(object);

    switch (property_id)
    {
    case PROP_FILENAME:
        g_free(self->filename);
        self->filename = g_value_dup_string(value);
        g_print("filename: %s\n", self->filename);
        break;

    case PROP_ZOOM_LEVEL:
        self->zoom_level = g_value_get_uint(value);
        g_print("zoom level: %u\n", self->zoom_level);
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        break;
    }
}

static void my_object1_init(MyObject1 *self)
{
    g_print("%s\n", "my_object1_init");
}

static void my_object1_class_init(MyObject1Class *klass)
{
    g_print("%s\n", "my_object1_class_init");

    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->set_property = my_object1_set_property;
    object_class->get_property = my_object1_get_property;

    obj_properties[PROP_FILENAME] =
        g_param_spec_string("filename",
                            "Filename",
                            "Name of the file to load and display from.",
                            NULL /* default value */,
                            G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    obj_properties[PROP_ZOOM_LEVEL] =
        g_param_spec_uint("zoom-level",
                          "Zoom level",
                          "Zoom level to view the file at.",
                          0 /* minimum value */,
                          10 /* maximum value */,
                          2 /* default value */,
                          G_PARAM_READWRITE);

    g_object_class_install_properties(object_class,
                                      N_PROPERTIES,
                                      obj_properties);
}
