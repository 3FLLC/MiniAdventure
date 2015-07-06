{%MainUnit: miniadv.p} // (c)opyright 2015 by 3F, LLC.
(* source file unit2.inc *)

(*****************************************************************************)
(*      procedure ogreaction                                                 *)
(*****************************************************************************)
PROCEDURE ogreaction;
BEGIN
   IF NOT awake THEN BEGIN
      TextColor(Yellow);
      writeln ("This is the ogre's lair!");
      TextColor(LightGray);
      writeln ("If you are not careful, you'll wake him.");
      IF (turns MOD 7 ) =0 THEN BEGIN
        awake := true;
        writeln ("Now you've done it! You woke the ogre - better get out while you still can!!");
      END;
   END
   ELSE BEGIN
      writeln ("You wouldn't listen to me would you?  You really better get out");
      writeln ("of here before you get eaten!");

      IF carrying THEN
        IF (turns MOD 2) = 0 THEN BEGIN
           writeln ("Too bad!! The ogre caught you and roasted you for dinner.");
           writeln ("Better luck next time!!");
           eaten := true;
           quit  := true;
        END
        ELSE BEGIN
           writeln ("Get out fast if you don't want to be a meal for the ogre!!");
        END
      ELSE
        IF (turns MOD 5) = 0 THEN BEGIN
           writeln ("Too bad - you've been eaten!");
           eaten := true;
           quit := true;
        END
   END; (* if not awake *)
END; (* procedure ogreaction *)

(*****************************************************************************)
(*      procedure pstart                                                     *)
(*****************************************************************************)

PROCEDURE pstart;
BEGIN
   IF carrying THEN done := true
   ELSE BEGIN
      writeln ("You are standing by a hole in the ground. It looks big enough to climb down.");
      CASE whichway OF
        n,s,e,w:noway;
        u:writeln ("You can't jump to the clouds!!");
        d:location := vestibule;
      END; (* case *)
   END; (* if carrying *)
END; (* procedure pstart *)

(*****************************************************************************)
(*      procedure pvestibule                                                 *)
(*****************************************************************************)
PROCEDURE pvestibule;
BEGIN
   writeln ("You are in the entrance to a cave of passageways. There are halls");
   writeln ("leading off to the north, south,and east. Above you is a tunnel");
   writeln ("leading to the surface.");
   IF dropped THEN BEGIN
      writeln ("To the north, through a narrow crack,you can see the treasure. If you");
      writeln ("stretch your arm through you might reach it. Do you want to try?");
      IF IsYes THEN BEGIN
        carrying := true;
        dropped := false;
      END; (* if *)
   END;
   CASE whichway OF
      n:location := narrow1;
      s:location := grandroom;
      e:location := iceroom;
      w,d:noway;
      u:location := start;
   END; (* case *)
END; (* procedure pvestibule *)

(*****************************************************************************)
(*      procedure pgrandroom                                                 *)
(*****************************************************************************)
PROCEDURE pgrandroom;
BEGIN
   writeln ("You are in a huge open room, with an immense expanse of ceiling.");
   writeln ("A dark passage leads west and a narrow crack leads downward.");
   CASE whichway OF
      w:location := brink;
      d:location := iceroom;
      n,s,e,u:noway;
   END; (* case *)
END; (* procedure pgrandroom *)

(*****************************************************************************)
(*      procedure pnarrow1                                                   *)
(*****************************************************************************)
PROCEDURE pnarrow1;
BEGIN
   writeln ("You are in a narrow passage which continues to the north. It is");
   writeln ("extremely narrow to the south.");
   writeln ("  A very tight crawl also leads east...");
   writeln ("A curious odor seeps through it. I would think twice before trying");
   writeln ("to go that way!");
   IF carrying THEN BEGIN
      writeln ("The treasure won't fit through the crack going south. Do you want");
      writeln ("to leave it here?");
      IF IsYes THEN BEGIN
        dropped := true;
        carrying := false;
      END; (* if *)
   END; (* if carrying *)
   CASE whichway OF
      n:location := lakeshore;
      e:location := ogreroom;
      s:writeln ("It's too narrow to get through!");
      w,u,d:noway;
   END; (* case *)
END; (* procedure pnarrow1 *)

(*****************************************************************************)
(*      procedure plakeshore                                               *)
(*****************************************************************************)
PROCEDURE plakeshore;
BEGIN
   writeln ("You are on the shore of a vast underground lake. Narrow passages");
   writeln ("wind away to the east and south. A small island is visible in the");
   writeln ("center of the lake to the north.");
   CASE whichway OF
      n:location := island;
      s:location := narrow1;
      e:location := narrow2;
      w,u,d:noway;
   END; (* case *)
END; (* procedure plakeshore *)

(*****************************************************************************)
(*      procedure pisland                                                    *)
(*****************************************************************************)
PROCEDURE pisland;
BEGIN
   writeln ("You are on a small island in the middle of a huge underground lake.");
   writeln ("Dark frigid waters surround you on all sides. You can barely make out");
   writeln ("the shoreline to the south. A small message is scratched in the");
   writeln ("dirt here. It says: 'The treasure may be found in the maze.'");
   CASE whichway OF
      n,e,w,u,d:noway;
      s:location := lakeshore;
   END; (* case *)
   readmsg := true;
END; (* procedure pisland *)

(*****************************************************************************)
(*      procedure pbrink                                                     *)
(*****************************************************************************)
PROCEDURE pbrink;
BEGIN
   writeln ("You are on the bottom of a steep incline. The bottom of the pit");
   writeln ("is over 50 feet below you. You could probably slide down, safely,");
   writeln ("but I couldn't promise you that you could get back up.");
   writeln ("   To the west is a dark opening into a rubble-filled tunnel. A ");
   writeln ("vampire bat just flew out of it shreiking.");
   CASE whichway OF
      n,s,e,u:noway;
      w:location := ogreroom;
      d:location := pit;
   END; (* case *)
END; (* procedure pbrink *)

(*****************************************************************************)
(*      procedure piceroom                                                   *)
(*****************************************************************************)
PROCEDURE piceroom;
BEGIN
   writeln ("You are in a room whose walls are made of a deep blue crystalline ice. To the");
   writeln ("north a narrow tunnel opens. From the other end of the tunnel an ominous");
   writeln ("growling sound may be heard. To the east a sparkling luminescence emanates");
   writeln ("from a broad opening. To the west a passage leads back to the vestibule.");
   CASE whichway OF
      e:location := crystal;
      n:location := ogreroom;
      w:location := vestibule;
      s,u,d:noway;
   END; (* case *)
END; (* procedure piceroom *)

(*****************************************************************************)
(*      procedure pogreroom                                                  *)
(*****************************************************************************)
PROCEDURE pogreroom;
VAR
   i,j:         INTEGER;

   PROCEDURE generaldescription;
   BEGIN
      writeln ("You are in a low room whose walls are covered with ominous dark blots");
      writeln ("of dried blood. The center of the room is dominated by a firepit, which");
      writeln ("contains burned-out coals and a long spit suspended over it's center.");
      writeln ("   From one dark corner emanates a horrible growling noise like that");
      writeln ("of some unspeakable monster snoring during it's dream of rending you limb");
      writeln ("from limb and making you it's dinner!");
   END; (* procedure generaldescription *)

BEGIN
   generaldescription;
   ogreaction;
   IF NOT eaten THEN BEGIN
      writeln ("There are exits to the east, west, north, and south.");
      CASE whichway OF
         w:location := narrow1;
         e:location := batscave;
         n:location := narrow2;
         s:location := iceroom;
         d: BEGIN
            quit := true;
            eaten := true;
            writeln ("Oh No!! You dummy!!!!");
            writeln ("You just fell into the firepit and made such a ruckus that");
            writeln ("you woke the ogre. I hate to tell you this, but you are also");
            writeln ("trapped!");
            FOR i := 1 to 5 DO BEGIN
               Delay(Random(100,200));
               write (".")
            END;
            writeln ("You have been added to the ogre's gourmet recipe library!");
            writeln ("Better luck next time!");
         END;
         u:noway;
      END; (* case *)
   END; (* if not eaten *)
END; (* procedure pogreroom *)
