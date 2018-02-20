#ifndef __MESSAGES_H__
#define __MESSAGES_H__

/*
 * Messages for main.c
 */

#define MSG_MAIN_WRONG_INPUT "Please specify a correct input."

/*
 * Messages for deplacement.c
 */

#define MSG_DEPLACEMENTS_UP "Chicken moves up."
#define MSG_DEPLACEMENTS_DOWN "Chicken moves down."
#define MSG_DEPLACEMENTS_LEFT "Chicken moves left."
#define MSG_DEPLACEMENTS_RIGHT "Chicken moves right."
#define MSG_DEPLACEMENTS_IMPOSSIBLE "Impossible to move here!"

/*
 * Messages for orientation.c
 */

#define MSG_ORIENTATION_NORTH "Chicken looks north."
#define MSG_ORIENTATION_SOUTH "Chicken looks south."
#define MSG_ORIENTATION_EAST "Chicken looks east."
#define MSG_ORIENTATION_WEST "Chicken looks west."

/*
 * Messages for inventaire.c
 */

#define MSG_INVENTORY_ITEM_ADDED "New item added in inventory."
#define MSG_INVENTORY_ITEM_NDEF "New definition of item."
#define MSG_INVENTORY_ITEM_NOTDEF "New definition of item has failed."
#define MSG_INVENTORY_ITEM_DEL "The item has been deleted."
#define MSG_INVENTORY_ITEM_NDEL "The item has not been deleted : not found."

/*
 * Messages for actions.c
 */

#define MSG_ACTIONS_TAKEKEY "Chicken takes the key."
#define MSG_ACTIONS_OPENDOOR "Chicken opened the door."
#define MSG_ACTIONS_ALREADY_DOWN "Chicken is already lying."
#define MSG_ACTIONS_DOWN "Chicken lied down."
#define MSG_ACTIONS_ALREADY_UP "Chicken is already standing."
#define MSG_ACTIONS_UP "Chicken stands up."
#define MSG_ACTIONS_DONOTHING "Doing nothing."

#endif
