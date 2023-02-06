/* 

Simple Notification
    Include

    Version 1.0
*/

#include <a_samp>
//Advertencia, el include requiere de Y_HOOKS para poder funcionar.

new NotificationTD[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    NotificationTD[playerid] = CreatePlayerTextDraw(playerid, 320.000000, 405.513946, " ");
    PlayerTextDrawLetterSize(playerid, NotificationTD[playerid], 0.449999, 1.600000);
    PlayerTextDrawAlignment(playerid, NotificationTD[playerid], 2);
    PlayerTextDrawColor(playerid, NotificationTD[playerid], -1);
    PlayerTextDrawSetShadow(playerid, NotificationTD[playerid], 0);
    PlayerTextDrawSetOutline(playerid, NotificationTD[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, NotificationTD[playerid], 51);
    PlayerTextDrawFont(playerid, NotificationTD[playerid], 2);
    PlayerTextDrawSetProportional(playerid, NotificationTD[playerid], 1);
}

stock Notification(playerid, const text[], time = 3000)
{
    TextDrawShowForPlayer(playerid, NotificationTD[playerid]);
    TextDrawSetString(NotificationTD[playerid], text[]);

    SetTimerEx("HideNotification", time, false, "d", playerid);
}

forward HideNotification(playerid, time);
public HideNotification(playerid, time)
{
    TextDrawHideForPlayer(playerid, NotificationTD[playerid]);
}