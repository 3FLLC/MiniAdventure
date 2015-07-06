{%MainUnit: miniadv.p} // (c)opyright 2015 by 3F, LLC.
(* source file unit1.inc *)

(***************************************************************************)
(*      Introduction                                                       *)
(***************************************************************************)
PROCEDURE introduction;
BEGIN
   ClrScr;
   TextColor(Yellow);
   writeln ("Welcome to mini-adventure!");
   TextColor(White);
   writeln ("Your goal will be to find a treasure and bring it back to the starting point.");
   writeln ("You will also get points for finding each location in the adventure. Points");
   writeln ("will be deducted for various undesirable happenings: waking the ogre, getting");
   writeln ("eaten, getting toasted, etc.");
   writeln();
   writeln ("I will guide you and be your eyes and ears. I will describe your location and");
   writeln ("give you special instructions from time to time.");
   writeln();
   TextColor(LightCyan);
   writeln ("To command me, simply tell me a direction to take:");
   writeln ("north, south, east, west, up, or down.");
   writeln ("Note: I only look at the first letter of the command, so abbreviations are");
   writeln ("acceptable. When you are ready to begin your adventure just press <RETURN>.");
   readkey;
   TextColor(LightGray);
   ClrScr;
END; (* procedure introduction *)

(*****************************************************************************)
(*      score                                                                *)
(*****************************************************************************)
FUNCTION score: INTEGER;
VAR
   loc:         rooms;
   sc:          INTEGER;

BEGIN
   sc           := 0;
   FOR loc := start TO flames DO
      IF visited[loc] THEN sc := sc + 10;
   IF NOT quit THEN sc := sc + 30;
   IF cooked THEN sc := sc - 50;
   IF eaten THEN sc := sc - 50;
   IF awake THEN sc := sc - 25;
   Result := sc;
END; (* function score *)

(*****************************************************************************)
(*      congratulations                                                         *)
(*****************************************************************************)
PROCEDURE congratulations;
BEGIN
   TextColor(LightRed);
   IF NOT cooked THEN BEGIN
        IF NOT quit THEN BEGIN
           TextColor(Yellow);
           writeln ("******************** Congratulations ********************");
           writeln();
           TextColor(White);
           write("You got out the treasure in only ");
           TextColor(LightRed);
           write(turns);
           TextColor(White);
           Writeln(" turns.");
        END;
        TextColor(LightGreen);
        writeln ("You scored ", score, " points out of a maximum of 200 points.");
        writeln ("So long for now, come again soon!");
   END
   ELSE writeln ("Sorry about that -- try again soon.");
   TextColor(LightGray);
   readkey;
   ClrScr;
END; (* procedure congratulations *)

(*****************************************************************************)
(*      function whichway                                                    *)
(*****************************************************************************)
FUNCTION whichway: directions;
BEGIN
   turns := turns + 1;
   REPEAT
        REPEAT
           writeln();
           write ("Which way? ==> ");
           command:=Lowercase(ReadKey);
        UNTIL Ord(command[1]) > 0;
        ch := command[1];
        CASE ch OF
           'n':Result:= n;
           's':Result:= s;
           'e':Result:= e;
           'w':Result:= w;
           'u':Result:= u;
           'd':Result:= d;
           'q':quit:= true;
        END; (* case *)
   UNTIL Pos(ch,dchars)>0;
   writeln();
END; (* function whichway *)

(*****************************************************************************)
(*      procedure noway                                                      *)
(*****************************************************************************)
PROCEDURE noway;
BEGIN
   writeln();
   TextColor(LightRed);
   writeln ("You can't go in that direction.");
   TextColor(LIghtGray);
END; (* procedure noway *)

(***************************************************************************)
(*      function isyes                                                     *)
(***************************************************************************)
FUNCTION IsYes: Boolean;
CONST
   YesNo='YyNn';

VAR
   C : Char;
   OK: Boolean;

BEGIN
   REPEAT
      C:=Readkey; // Read (Kbd, C);
      OK := Pos(C,YesNo)>0;
      IF NOT Ok THEN write(#7);
   UNTIL OK;
   Result:= (Upcase(C) = 'Y');
END; (* function isyes *)
