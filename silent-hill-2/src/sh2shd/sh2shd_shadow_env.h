#ifndef SH2SHD_SHADOW_ENV_H
#define SH2SHD_SHADOW_ENV_H

void sh2shd_get_shadow_env_bg(struct SHADOW_ENV* env, struct SHADOW_OUTDOOR_HEAD* head);

void sh2shd_get_shadow_env_chr(struct SHADOW_ENV* env, struct SHADOW_CHAR_MAN* chr_man, int glb_coord, int map_id);

void sh2shd_get_demo_shadow_env_for_bg(struct SHADOW_ENV* env, int demo_no);

void sh2shd_get_demo_shadow_env_for_char(struct SHADOW_ENV* env, struct SHADOW_CHAR_MAN* man, int demo_no);

void sh2shd_get_jms_shadow_env(struct JMS_SHADOW_ENV* env, int light_kind, float* light_dir);

void sh2shd_get_demo_jms_shadow_env(struct JMS_SHADOW_ENV* env, int demo_no);

void sh2shd_get_drop_shadow_env(struct DROP_SHADOW_ENV* env, int glb_coord, int map_id, float x, float z);

void sh2shd_get_demo_drop_shadow_env(struct DROP_SHADOW_ENV* env, int demo_no);

void sh2shd_demo_shadow_off(int demo_no);

void sh2shd_shadow_off(int glb_coord, int map_id);

void get_map_id(int* glb_coord, int* map_id);

int check_bg_light_exist(void);


#endif // SH2SHD_SHADOW_ENV_H
