#ifndef __SMTK_KEYS_EMITTER__
#define __SMTK_KEYS_EMITTER__

#include <stdbool.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define SMTK_TYPE_KEYS_EMITTER smtk_keys_emitter_get_type()
G_DECLARE_FINAL_TYPE(SmtkKeysEmitter, smtk_keys_emitter, SMTK, KEYS_EMITTER,
		     GObject)

// It looks like glib-mkenums cannot make enums
// if clang-format make this in one line. But why???
// clang-format off
typedef enum {
	SMTK_KEY_MODE_COMPOSED,
	SMTK_KEY_MODE_RAW
} SmtkKeyMode;
// clang-format on

SmtkKeysEmitter *smtk_keys_emitter_new(bool show_mouse, SmtkKeyMode mode,
				       GError **error);
void smtk_keys_emitter_start_async(SmtkKeysEmitter *emitter, GError **error);
void smtk_keys_emitter_stop_async(SmtkKeysEmitter *emitter);
void smtk_keys_emitter_set_show_mouse(SmtkKeysEmitter *emitter,
				      bool show_mouse);
void smtk_keys_emitter_set_mode(SmtkKeysEmitter *emitter, SmtkKeyMode mode);

G_END_DECLS

#endif
