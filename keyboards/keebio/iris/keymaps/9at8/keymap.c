#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _MAC 1
#define _GAME 2
#define _LOWER 3
#define _RAISE 4
#define _MAC_RAISE 5
#define _FN 6
#define _ADJUST 7

// Adjust LEDs using the rotary encoder
#define _RGB_HUE 10
#define _RGB_SAT 11
#define _RGB_VAL 12

enum keycodes {
    QWERTY = SAFE_RANGE,

    MAC_RS,

    WD_L,
    WD_R,

    MAC_WD_L,
    MAC_WD_R,

    DND_RGB,
    NOR_RGB
};

#define MAC TG(_MAC)
#define GAME TG(_GAME)
#define LW_ENT LT(_LOWER, KC_ENT)
#define RAISE MO(_RAISE)
#define FN MO(_FN)

#define L_RGB_HU MO(_RGB_HUE)
#define L_RGB_SA MO(_RGB_SAT)
#define L_RGB_VA MO(_RGB_VAL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * .-----------------------------------------.                                     .-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                                     |   6  |   7  |   8  |   9  |   0  |  Del |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                     |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |Shift |   A  |   S  |   D  |   F  |   G  |                                '==' |   H  |   J  |   K  |   L  |   ;  |   '  |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * | Esc  |   Z  |   X  |   C  |   V  |   B  |  Fn  |                       | MsWhl|   N  |   M  |   ,  |   .  |   /  | Shift|
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          | Alt  | Ctrl |LW+Ent|                             | Spc  | RAI  | Gui  |
     *                          '--------------------'                             '--------------------'
     */

    [_QWERTY] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_GRV,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                              KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,  KC_DEL,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                              KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSPC,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_LSFT,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                              KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_ESC,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,   FN   ,           _______,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        /*                             */ KC_LALT, KC_LCTL, LW_ENT ,                    KC_SPC , RAISE  , KC_RGUI
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    /* MAC
     * .-----------------------------------------.                                     .-----------------------------------------.
     * |      |      |      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                '==' |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                       |      |      |      |      |      |      |      |
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          |      |      |      |                             |      |MAC_RS|      |
     *                          '--------------------'                             '--------------------'
     */


    [_MAC] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                    _______, MAC_RS , _______
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    /* Game
     * .-----------------------------------------.                                     .-----------------------------------------.
     * |      |      |      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                '==' |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                       | MsLR |      |      |      |      |      |      |
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          |      |      |      |                             |      |      |      |
     *                          '--------------------'                             '--------------------'
     */


    [_GAME] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                    _______, _______, _______
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    /* Lower
     * .-----------------------------------------.                                     .-----------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |                                     |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |                                     |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |      |  DND |RGB_HU|RGB_SA|RGB_VA|      |                                '==' |      |   -  |   =  |   [  |   ]  |   \  |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * |      |RGB_RB|Rgb Rg|      |      |      |      |                       | Brght|      |   _  |   +  |   {  |   }  |   |  |
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          |      |      | #### |                             |      |      |      |
     *                          '--------------------'                             '--------------------'
     */

    [_LOWER] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_TILD, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_GRV,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                              KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, DND_RGB,L_RGB_HU,L_RGB_SA,L_RGB_VA, _______,                             _______, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, NOR_RGB, RGB_TOG, _______, _______, _______, _______,           _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        /*                             */ _______, _______, _______,                    _______, _______, _______
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    /* Raise
     * .-----------------------------------------.                                     .-----------------------------------------.
     * |      |      |      |      |      |      |                                     |      |      | Pg U |      |      |      |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * |      |      |      |McrStp|      |      |                                     |      | WD L |  Up  | WD R |      |      |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |      |      |      |McrRec|McrPly|      |                                '==' |      | Left | Down | Rght |      |      |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                       |      |      | Home | Pg D | End  |      |      |
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          |      |      |      |                             |      | #### |      |
     *                          '--------------------'                             '--------------------'
     */

    [_RAISE] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, _______, _______, _______, _______, _______,                             _______, _______, KC_PGUP, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, DM_RSTP, _______, _______,                             _______,  WD_L  ,  KC_UP ,  WD_R  , _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, DM_REC1, DM_PLY1, _______,                             _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, KC_HOME, KC_PGDN, KC_END , _______, _______,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                    _______, _______, _______
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    /* MAC Raise
     * .-----------------------------------------.                                     .-----------------------------------------.
     * |      |      |      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                     |      |MAC WL|      |MAC WR|      |      |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                '==' |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                       |      |      |      |      |      |      |      |
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          |      |      |      |                             |      |      |      |
     *                          '--------------------'                             '--------------------'
     */


    [_MAC_RAISE] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______,MAC_WD_L, _______,MAC_WD_R, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                    _______, _______, _______
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    /* Function
     * .-----------------------------------------.                                     .-----------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                                     |  F6  |  F7  |  F8  |  F9  |  F10 |      |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * |      |  F11 |  F12 |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                '==' |      | Prev | Play | Next |      |      |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                       |  Vol |      |      |      |      |      |      |
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          |      |      |      |                             |      |      |      |
     *                          '--------------------'                             '--------------------'
     */


    [_FN] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                              KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_F11 , KC_F12 , _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                    _______, _______, _______
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    /* Adjust
     * .-----------------------------------------.                                     .-----------------------------------------.
     * | RESET| DEBUG|      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                '==' |      | GAME |  MAC |      |      |      |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                       |      |      |      |      |      |      |      |
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          |      |      | #### |                             |      | #### |      |
     *                          '--------------------'                             '--------------------'
     */

    [_ADJUST] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
            RESET ,  DEBUG , _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______,  GAME  ,   MAC  , _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                    _______, _______, _______
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    /* ------------------------ LED Adjustment Layers -------------------------- */

    [_RGB_HUE] = LAYOUT(
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,                    _______, _______, _______
    ),

    [_RGB_SAT] = LAYOUT(
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,                    _______, _______, _______
    ),

    [_RGB_VAL] = LAYOUT(
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,                    _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LW_ENT:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;

    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;

    case MAC_RS:
        if (record->event.pressed) {
            layer_on(_RAISE);
            layer_on(_MAC_RAISE);
        } else {
            layer_off(_MAC_RAISE);
            layer_off(_RAISE);
        }
        return false;

    case ADJUST:
        if (record->event.pressed) {
            layer_on(_ADJUST);
        } else {
            layer_off(_ADJUST);
        }
        return false;

    /* ------------------- Macros --------------------- */
    /* Word left - Move one word left */
    case WD_L:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_LEFT) SS_UP(X_LCTRL));
        }
        return false;
    case MAC_WD_L:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LALT));
        }
        return false;

    /* Word right - Move one word right */
    case WD_R:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL));
        }
        return false;
    case MAC_WD_R:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LALT));
        }
        return false;

    /* ------------------- LEDs --------------------- */
    case DND_RGB:
        if (record->event.pressed) {
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_RED);
        }
        return false;

    case NOR_RGB:
        if (record->event.pressed) {
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
            rgblight_sethsv(0, 170, 170);
        }
        return false;

    default: break;
    }

    return true;
}

void encoder_update_user(uint8_t _index, bool clockwise) {
    if (IS_LAYER_ON(_RGB_HUE)) {
        // rgb hue + -
    } else if (IS_LAYER_ON(_RGB_SAT)) {
        // rgb sat + -
    } else if (IS_LAYER_ON(_RGB_VAL)) {
        // rgb val + -
    } else if (IS_LAYER_ON(_FN)) {
        // vol + -
    } else if (IS_LAYER_ON(_LOWER)) {
        // brightness + -
    } else if (IS_LAYER_ON(_GAME)) {
        // mouse left / right
    } else {
        // mouse wheel up down
    }
}

/*

Template

     <change me>
     * .-----------------------------------------.                                     .-----------------------------------------.
     * |      |      |      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                .==. |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                                '==' |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------.                       .--||--+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                       |      |      |      |      |      |      |      |
     * '------------------------+------+------+------+--'                       '--+------+------+------+------------------------'
     *                          |      |      |      |                             |      |      |      |
     *                          '--------------------'                             '--------------------'


    [_<change me>] = LAYOUT(
        //┌───────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘         └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                    _______, _______, _______
        //                              └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

*/
