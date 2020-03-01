PROGRAM rologia;

TYPE
  array9 = array[1..9] of byte;

VAR
  input, output : text;
  i, a : integer;
  tropoi : array[1..9,1..6] of byte;
  kiniseis, thesi, comp : array9;

procedure initialize;
begin
  tropoi[1,1] := 4;
  tropoi[1,2] := 1;
  tropoi[1,3] := 2;
  tropoi[1,4] := 4;
  tropoi[1,5] := 5;
  tropoi[2,1] := 3;
  tropoi[2,2] := 1;
  tropoi[2,3] := 2;
  tropoi[2,4] := 3;
  tropoi[3,1] := 4;
  tropoi[3,2] := 2;
  tropoi[3,3] := 3;
  tropoi[3,4] := 5;
  tropoi[3,5] := 6;
  tropoi[4,1] := 3;
  tropoi[4,2] := 1;
  tropoi[4,3] := 4;
  tropoi[4,4] := 7;
  tropoi[5,1] := 5;
  tropoi[5,2] := 2;
  tropoi[5,3] := 4;
  tropoi[5,4] := 5;
  tropoi[5,5] := 6;
  tropoi[5,6] := 8;
  tropoi[6,1] := 3;
  tropoi[6,2] := 3;
  tropoi[6,3] := 6;
  tropoi[6,4] := 9;
  tropoi[7,1] := 4;
  tropoi[7,2] := 4;
  tropoi[7,3] := 5;
  tropoi[7,4] := 7;
  tropoi[7,5] := 8;
  tropoi[8,1] := 3;
  tropoi[8,2] := 7;
  tropoi[8,3] := 8;
  tropoi[8,4] := 9;
  tropoi[9,1] := 4;
  tropoi[9,2] := 5;
  tropoi[9,3] := 6;
  tropoi[9,4] := 8;
  tropoi[9,5] := 9;
  end;

function generate : array9;
var j : integer;
begin
  generate := thesi;
  for a := 1 to 9 do
    for j := 1 to kiniseis[a] do
      for i := 2 to tropoi[a,1]+1 do
        generate[tropoi[a,i]] := generate[tropoi[a,i]]+1;
  for a := 1 to 9 do
    if generate[a] > 3 then
      generate[a] := generate[a] mod 4;
  end;

procedure next;
begin
  kiniseis[9] := kiniseis[9]+1;
  i := 9;
  while kiniseis[i] = 4 do
  begin
    kiniseis[i] := 0;
    i := i-1;
    kiniseis[i] := kiniseis[i]+1;
    end;
  end;

BEGIN
  initialize;
  assign (input,'clocks.in');
  reset (input);
  assign (output,'clocks.out');
  rewrite (output);
  for i := 1 to 9 do
  begin
    kiniseis[i] := 0;
    read (input,thesi[i]);
    end;
  repeat
    next;
    comp := generate;
    until (comp[1] = 0) and (comp[2] = 0) and (comp[3] = 0) and (comp[4] = 0) and (comp[5] = 0) and (comp[6] = 0) and (comp[7] = 0) and (comp[8] = 0) and (comp[9] = 0);
  for a := 1 to 9 do
    for i := 1 to kiniseis[a] do
      write (output,a,' ');
  close (output);
  END.

