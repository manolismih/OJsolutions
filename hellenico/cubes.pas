PROGRAM cubemania;

VAR
  stiles : array[1..1000] of longint;
  cubes : longint;
  alma, numofstiles : integer;
  input, output : text;

procedure correct_numofstiles;
begin
  if stiles[numofstiles+1] > 0 then
    numofstiles := numofstiles+1;
  end;

procedure fix(stili:integer); forward;
procedure check;
var stili : integer; stop : boolean;
begin
  stop := false;
  stili := 0;
  repeat
    stili := stili+1;
    if stiles[stili]-stiles[stili+1] > alma then
      begin
      fix(stili);
      stop := true;
      end;
    until (stop = true) or (stili = numofstiles);
  end;

procedure fix (stili:integer);
begin
  while stiles[stili]-stiles[stili+1] > alma do
    begin
    stiles[stili] := stiles[stili]-1;
    stiles[stili+1] := stiles[stili+1]+1;
    end;
  correct_numofstiles;
  check;
  end;

BEGIN
  assign (input,'cubes.in');
  assign (output,'cubes.out');
  reset (input);
  rewrite (output);
  read (input,cubes,alma);
  for numofstiles := 1 to 1000 do
    stiles[numofstiles] := 0;
  stiles[1] := cubes;
  numofstiles := 1;
  check;
  write (output,stiles[1]);
  close (input);
  close (output);
END.

