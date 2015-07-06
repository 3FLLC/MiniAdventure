{%MainUnit: miniadv.p} // (c)opyright 2015 by 3F, LLC.
(* source file unit4.inc *)

(*****************************************************************************)
(*      procedure pnarrow2                                                       *)
(*****************************************************************************)
PROCEDURE pnarrow2;
BEGIN
   writeln ("You are in a very narrow passage.");
   writeln ("To the west the passage opens out by a lake shore. To the east it is even");
   writeln ("tighter. You might be able to squeeze through if you try real hard.");
   writeln ("   There is also a strange looking alcove in the south wall that seems to");
   writeln ("open into a very dark tunnel.");
   CASE whichway OF
      w:location := lakeshore;
      e:location := steam;
      s:location := ogreroom;
      n,u,d:noway;
   END; {case}
END; {proc pnarrow2}

(*****************************************************************************)
(*      procedure ppit                                                       *)
(*****************************************************************************)
PROCEDURE ppit;
BEGIN
   writeln ("You are at the bottom of a fifty foot pit. The walls are just a hair too steep");
   writeln ("to climb. The pit is empty except for a few old dried bones - I can't tell if");
   writeln ("they are human or not!!");
   writeln ("In the center of the pit is a narrow shinny leading downward.");
   CASE whichway OF
      d:location := ladder;
      u:BEGIN
          writeln ("If you try to climb that, you're sure to kill yourself!");
        END;
      n,s,e,w:noway;
   END; {case}
END; {proc ppit}

(*****************************************************************************)
(*      procedure pcrystal                                                       *)
(*****************************************************************************)
PROCEDURE pcrystal;
BEGIN
   writeln ("You are in a shining hall of crystal. It is intensely cold but also chillingly");
   writeln ("beautiful. There are glass formations rising from the floor as if they had");
   writeln ("grown there, yet delicately sculptured with multi-faceted sides. An intense");
   writeln ("white light shines brilliantly from the floor, which is also made of a mirror");
   writeln ("smooth lead crystal. The light is almost blinding and the many reflections");
   writeln ("that it sets off among the crystal formations of the room make it almost");
   writeln ("impossible to tell where the room begins and where it ends.");
   CASE whichway OF
      e:location := maze;
      n,w:location := ogreroom;
      s,u,d:noway;
   END; {case}
END; {proc pcrystal}

(*****************************************************************************)
(*      procedure pbatscave                                                       *)
(*****************************************************************************)
PROCEDURE pbatscave;
BEGIN
   writeln ("You are in a steep cavern filled with shrieking vampire bats. They swoop and");
   writeln ("dive at you by the thousands. If I were you, I would get out as quickly as I");
   writeln ("could. There are openings to the west and to the north.");
   CASE whichway OF
      w:location := ogreroom;
      n:location := steam;
      e,s,u,d:noway;
   END; {case}
END; {proc pbatscave}

(*****************************************************************************)
(*      procedure psteam                                                       *)
(*****************************************************************************)
PROCEDURE psteam;
BEGIN
   writeln ("You have entered a hall filled with a stifling steamy vapor. There are");
   writeln ("innumerable small geysers scattered about, each contributing its own steam");
   writeln ("to the general mist.");
   writeln ("To the west is a dark opening, as well as to the north. Further out in the");
   writeln ("middle of the room is a dark opening in the floor into which some of the");
   writeln ("vapor seems to be seeping.");
   CASE whichway OF
      w:location := narrow2;
      n:location := deadend;
      d:location := maze;
      s:location := batscave;
      e,u:noway;
   END; {case}
END; {proc psteam}

(*****************************************************************************)
(*      procedure pladder                                                       *)
(*****************************************************************************)
PROCEDURE pladder;
BEGIN
   writeln ("You are at the base of a huge ladder reaching up out of sight. It must extend");
   writeln ("up at least 500 feet, and it will take someone brave in heart to scale it.");
   writeln ("There are also passages which lead north and down.");
   CASE whichway OF
      n:location := maze;
      d:location := flames;
      u:IF carrying THEN BEGIN
           writeln ("You can't carry the treasure up the ladder --  it's much too heavy!");
        END
        ELSE location := vestibule;
        {endif}
      e,s,w:noway;
   END; {case}
END; {proc pladder}

(*****************************************************************************)
(*      procedure pflames                                                       *)
(*****************************************************************************)
PROCEDURE pflames;
BEGIN
   writeln ("Unfortunately you have fallen into an underground fire pit. It is the source");
   writeln ("of heat that produces the geysers in the steam room. You have been toasted");
   writeln ("to a crisp, to put it politely.");
   cooked := true;
   done := true;
END; {proc pflames}

(*****************************************************************************)
(*      procedure pdeadend                                                       *)
(*****************************************************************************)
PROCEDURE pdeadend;
BEGIN
   writeln ("Dead end.");
   CASE whichway OF
      s:location := steam;
      n,e,w,u,d:noway;
   END; {case}
END; {proc pdeadend}
