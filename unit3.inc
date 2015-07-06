{%MainUnit: miniadv.p} // (c)opyright 2015 by 3F, LLC.
(* source file unit3.inc *)

(*************************************************************************)
(*   procedure pmaze                                                                    *)
(*************************************************************************)
PROCEDURE pmaze;
TYPE
   mazerooms = (m1,m2,m3,m4,m5,m6,m7,m8,m9,
                m10,m11,m12,m13,m14,m15,m16,m17,m18,m19);
VAR
   mazeloc:     mazerooms;
   bitset:      ARRAY[directions] OF BOOLEAN;

   FUNCTION bittest (v: INTEGER; dir: directions): BOOLEAN;
   BEGIN
      Result:=((v DIV twopow[dir]) MOD 2) = 1;
   END; (* function bittest *)

   PROCEDURE describe(wh: INTEGER);
   VAR
      dir:     directions;

   BEGIN
      writeln ("You are in a maze of featureless passages. There are exits visible");
      writeln ("in the following directions:");
      if bittest (wh,n)  THEN write ('n ');
      if bittest (wh,s)  THEN write ('s ');
      if bittest (wh,e)  THEN write ('e ');
      if bittest (wh,w)  THEN write ('w ');
      if bittest (wh,u)  THEN write ('u ');
      if bittest (wh,d)  THEN write ('d ');
      writeln();
   END; (* procedure describe *)

   PROCEDURE sameplace;
   BEGIN
      writeln ("You have crawled around some twisted tunnels and wound up where you began.");
   END; (* proc sameplace *)

   PROCEDURE treasure;
   BEGIN
      IF NOT carrying THEN BEGIN
         IF readmsg THEN BEGIN
            writeln ("The treasure is here!!");
            writeln ("Do you want to take it now?");
            Command:=Uppercase(ReadKey);
            IF (command = 'Y') OR (command = 'YES') THEN carrying := true;
         END
         ELSE BEGIN
            writeln ("The light is extremely dim here.");
            writeln ("You better get out or risk falling into a pit.");
         END; (* if readmsg *)
      END; (* if not carrying *)
   END; (* proc treasure *)

   PROCEDURE pm1(var mazeloc:mazerooms);
   BEGIN
      writeln ("You are in a maze of featureless passages.");
      writeln ("From here you can go south, east, west or up.");
      CASE whichway OF
         s:location := ladder;
         e:mazeloc  := m2;
         w:mazeloc  := m4;
         u:location := steam;
         n,d:noway;
      END; (* case *)
   END; (* proc pm1 *)


PROCEDURE pm2(var mazeloc:mazerooms);
BEGIN
   describe (nw);
   CASE whichway OF
      n:mazeloc:= m1;
      w:sameplace;
      e,s,u,d:noway;
    END; (* case *)
END; (* proc pm2*)

PROCEDURE pm3(var mazeloc:mazerooms);
BEGIN
   describe (ne);
   CASE whichway OF
      n:mazeloc:= m1;
      e:sameplace;
      w,s,u,d:noway;
    END; (* case *)
END; (* proc pm3*)

PROCEDURE pm4(var mazeloc:mazerooms);
BEGIN
   describe (sew);
   CASE whichway OF
      s:mazeloc:= m7;
      e:mazeloc:= m3;
      w:mazeloc:= m5;
      n,u,d:noway;
    END; (* case *)
END; (* proc pm4*)

PROCEDURE pm5(var mazeloc:mazerooms);
BEGIN
   describe (nonly);
   CASE whichway OF
      n:mazeloc:= m1;
      s,e,w,u,d:noway;
    END; (* case *)
END; (* proc pm5*)

PROCEDURE pm6(var mazeloc:mazerooms);
BEGIN
   describe (ne);
   CASE whichway OF
      n:mazeloc:= m4;
      e:sameplace;
      s,w,u,d:noway;
    END; (* case *)
END; (* proc pm6*)

PROCEDURE pm7(var mazeloc:mazerooms);
BEGIN
   describe (nsew);
   CASE whichway OF
      n:mazeloc:= m5;
      s:mazeloc:= m9;
      e:mazeloc:= m6;
      w:mazeloc:= m8;
      u,d:noway;
    END; (* case *)
END; (* proc pm7*)


PROCEDURE pm8(var mazeloc:mazerooms);
BEGIN
   describe (nw);
   CASE whichway OF
      n:mazeloc:= m5;
      w:sameplace;
      e,s,u,d:noway;
    END; (* case *)
END; (* proc pm8*)


PROCEDURE pm9(var mazeloc:mazerooms);
BEGIN
   describe (sw);
   CASE whichway OF
      s:mazeloc:= m11;
      w:mazeloc:= m10;
      n,e,u,d:noway;
    END; (* case *)
END; (* proc pm9*)


PROCEDURE pm10(var mazeloc:mazerooms);
BEGIN
   describe (ns);
   CASE whichway OF
      s:sameplace;
      n:mazeloc:= m8;
      e,w,u,d:noway;
    END; (* case *)
END; (* proc pm10*)


PROCEDURE pm11(var mazeloc:mazerooms);
BEGIN
   describe (newud);
   CASE whichway OF
      n:mazeloc:= m9;
      e:mazeloc:= m6;
      w:mazeloc:= m10;
      u:mazeloc:= m1;
      d:mazeloc:= m12;
      s:noway;
    END; (* case *)
END; (* proc pm11*)


PROCEDURE pm12(var mazeloc:mazerooms);
BEGIN
   describe (dn);
   CASE whichway OF
      n:mazeloc:= m13;
      d:mazeloc:= m16;
      e,s,w,u:noway;
    END; (* case *)
END; (* proc pm12*)

PROCEDURE pm13(var mazeloc:mazerooms);
BEGIN
   describe (dn);
   CASE whichway OF
      n:mazeloc:= m14;
      d:mazeloc:= m17;
      e,s,w,u:noway;
    END; (* case *)
END; (* proc pm13*)

PROCEDURE pm14(var mazeloc:mazerooms);
BEGIN
   describe (dn);
   CASE whichway OF
      n:mazeloc:= m15;
      d:mazeloc:= m18;
      e,s,w,u:noway;
    END; (* case *)
END; (* proc pm14*)

PROCEDURE pm15(var mazeloc:mazerooms);
BEGIN
   describe (ud);
   CASE whichway OF
      u:mazeloc:= m1;
      d:mazeloc:= m19;
      n,e,s,w:noway;
    END; (* case *)
END; (* proc pm15*)

PROCEDURE pm16(var mazeloc:mazerooms);
BEGIN
   describe (ns);
   CASE whichway OF
      n:mazeloc:= m17;
      s:sameplace;
      e,w,u,d:noway;
    END; (* case *)
END; (* proc pm16*)


PROCEDURE pm17(var mazeloc:mazerooms);
BEGIN
   describe (ns);
   CASE whichway OF
      n:mazeloc:= m18;
      s:mazeloc:= m16;
      e,w,u,d:noway;
    END; (* case *)
END; (* proc pm17*)

PROCEDURE pm18(var mazeloc:mazerooms);
BEGIN
   describe (ns);
   CASE whichway OF
      n:mazeloc:= m19;
      s:mazeloc:= m17;
      e,w,u,d:noway;
    END; (* case *)
END; (* proc pm18*)

PROCEDURE pm19(var mazeloc:mazerooms);
BEGIN
   describe (su);
   treasure;
   CASE whichway OF
      s:mazeloc:= m18;
      u:mazeloc:= m15;
      n,e,w,d:noway;
    END; (* case *)
END; (* proc pm19*)


BEGIN (* proc pmaze *)
   mazeloc := m1;
   REPEAT
      CASE mazeloc OF
         m1:pm1(mazeloc);
         m2:pm2(mazeloc);
         m3:pm3(mazeloc);
         m4:pm4(mazeloc);
         m5:pm5(mazeloc);
         m6:pm6(mazeloc);
         m7:pm7(mazeloc);
         m8:pm8(mazeloc);
         m9:pm9(mazeloc);
         m10:pm10(mazeloc);
         m11:pm11(mazeloc);
         m12:pm12(mazeloc);
         m13:pm13(mazeloc);
         m14:pm14(mazeloc);
         m15:pm15(mazeloc);
         m16:pm16(mazeloc);
         m17:pm17(mazeloc);
         m18:pm18(mazeloc);
         m19:pm19(mazeloc);
      END; (* case *)
   UNTIL location <> maze;
END; (* proc pmaze *)
