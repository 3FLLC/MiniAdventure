(****************************************************************************)
(*                                                                          *)
(*               a d v e n t u r e # 1                                      *)
(*                                                                          *)
(*   This is an example of the PASCAL language features that are useful     *)
(*   in writing an adventure game.                                          *)
(*                                                                          *)
(****************************************************************************)
PROGRAM miniadv; // (c)opyright 2015 by 3F, LLC.

uses
   display, math;

CONST
        nw      =        9;
        ne      =        5;
        sew     =       14;
        nonly   =        1;
        nsew    =       15;
        newud   =       61;
        sw      =       10;
        ns      =        3;
        donly   =       32;
        dn      =       33;
        ud      =       48;
        su      =       18;

TYPE
        rooms   =       (start, grandroom, vestibule, narrow1,
                         lakeshore, island, brink, iceroom,
                         ogreroom, narrow2, pit, crystal,
                         batscave, steam, deadend, ladder,
                         maze, flames );
        directions =    (n, s, e, w, u, d);

VAR
        command:        STRING[10];(* holds user's typed direction *)
        ch:             CHAR;
        dchars:         STRING; (* characters which respond to the
                                   acceptable initial letters of the
                                   direction commands, initialized
                                   to DIRECTIONS *)
        location:       rooms;
        ogreloc:        rooms;
        visited:        ARRAY[start..flames] OF BOOLEAN;
        next:           directions;
        twopow:         ARRAY[n..d] OF INTEGER;
        turns:          INTEGER;
        done:           BOOLEAN;
        quit:           BOOLEAN;
        eaten:          BOOLEAN;
        awake:          BOOLEAN;
        readmsg:        BOOLEAN;
        carrying:       BOOLEAN;
        dropped:        BOOLEAN;
        trapped:        BOOLEAN;
        cooked:         BOOLEAN;

{$I unit1.inc}
{$I unit2.inc}
{$I unit3.inc}
{$I unit4.inc}

(*****************************************************************************)
(*      initialize                                                           *)
(*****************************************************************************)
PROCEDURE initialize;
VAR
   loc:         rooms;

BEGIN
   location     := start;
   dchars       := 'qnsewud';
   done         := false;
   quit         := false;
   cooked       := false;
   eaten        := false;
   awake        := false;
   readmsg      := false;
   carrying     := false;
   trapped      := false;
   dropped      := false;
   turns        := 0;
   twopow[n]    := 1;
   twopow[s]    := 2;
   twopow[e]    := 4;
   twopow[w]    := 8;
   twopow[u]    := 16;
   twopow[d]    := 32;
   FOR loc := start TO flames DO visited[loc] := false;
   (* enddo *)
END; (* procedure initialize *)

(*****************************************************************************)
(*      main program                                                         *)
(*****************************************************************************)
BEGIN
   introduction;
   initialize;
   REPEAT
      visited[location] := true;
      CASE location OF
         start:          pstart;
         grandroom:      pgrandroom;
         vestibule:      pvestibule;
         narrow1:        pnarrow1;
         lakeshore:      plakeshore;
         island:         pisland;
         brink:          pbrink;
         iceroom:        piceroom;
         ogreroom:       pogreroom;
         narrow2:        pnarrow2;
         pit:            ppit;
         crystal:        pcrystal;
         batscave:       pbatscave;
         steam:          psteam;
         deadend:        pdeadend;
         ladder:         pladder;
         maze:           pmaze;
         flames:         pflames;
      END; {case}
   UNTIL quit OR done;
   congratulations;
END.
