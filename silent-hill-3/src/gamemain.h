#ifndef SH3_GAMEMAIN_H
#define SH3_GAMEMAIN_H

#define SH3_GAME_MAIN_INIT           0
#define SH3_GAME_MAIN_MENU           1
#define SH3_GAME_MAIN_LOADING_SCREEN 2
#define SH3_GAME_MAIN_PLAYABLE       5
#define SH3_GAME_MAIN_INVENTORY      6
#define SH3_GAME_MAIN_MAP            9
#define SH3_GAME_MAIN_OPTION         14

/* @note Game states.
 * 1  = Main menu/splash screen
 * 2  = Loading screen
 * 5  = In-game
 * 6  = Inventory
 * 9  = Map
 * 14 = Option menu
 *
 * @note PC apparently shares the same list.
 *
 * @note SH2 counterpart and PC in Ghidra tells this function returns some 4 byte value.
 */
void GameMain(void);

#endif // SH3_GAMEMAIN_H
