#ifndef DEMOVIEW_H
#define DEMOVIEW_H

#include "common.h"

#define DRAMA_DEMO_9  0x9
#define DRAMA_DEMO_D  0xD
#define DRAMA_DEMO_E  0xE
#define DRAMA_DEMO_21 0x21
#define DRAMA_DEMO_26 0x26
#define DRAMA_DEMO_2E 0x2E
#define DRAMA_DEMO_41 0x41
#define DRAMA_DEMO_42 0x42
#define DRAMA_DEMO_4A 0x4A
#define DRAMA_DEMO_4E 0x4E

// total size: 0x4
typedef struct DramaDemo_MessageTime {
    // Members
    u_short start; // offset 0x0, size 0x2
    u_short end; // offset 0x2, size 0x2
} DramaDemo_MessageTime;

extern int sbt_msg_no;
extern DramaDemo_MessageTime* sbt_msg_time;
extern int sbt_str_no;
extern int demo_status;
extern u_short msg_buffer[];

#endif // DEMOVIEW_H
