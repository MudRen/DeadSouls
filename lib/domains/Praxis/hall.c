inherit "/lib/std/room";

void create() {
    ::create();
    SetProperties( ([ "light" : 1, "no castle" : 1 ]) );
    SetShort( "the Nightmare Inn" );
    SetLong( "The hallway is very quiet, you can barely hear the whisper "
            "of your feet against the rich carpet. Large wooden doors for each room "
            "stand both to your left and right, trimmed with gold. Small lanterns "
            "hang every 5 feet or so, giving off a gentle glow, lighting the way." );
    SetItems( ([ "hallway" : "The hallway is very quiet.",
                "carpet" : "It is a deep burgundy colour.",
                ({ "lanterns", "lanter" }) :
                "The lanterns are gold with glass panes.",
                "doors" : "The doors are large oaken barriers.",
                ]) );
    SetExits( ([ "north" : "/domains/Praxis/hall2",
                "south" : "/domains/Praxis/hotel",
                "east" : "/domains/Praxis/inn101",
                "west" : "/domains/Praxis/inn102",
                ]) );
    //set_pre_exit_functions( ({ "east", "west" }), ({ "room_101", "room_102" }) ); 
}

int room_101() {
    if(present("/domains/Praxis/hotel"->query_key_id(101),this_player()))
        return 1;
    write( "You cannot go in there!");
    return 0;
}

int room_102() {
    if(present("/domains/Praxis/hotel"->query_key_id(102),this_player()))
        return 1;
    write( "You cannot go in there!");
    return 0;
}

void init(){
    ::init();
}
