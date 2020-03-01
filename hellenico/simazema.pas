PROGRAM zimazema;

TYPE
  sintetagmenes = array[1..2] of integer;
  sindiasmos = record
    x, y : sintetagmenes;
    timi : integer;
    end;

VAR
  diastaseis, cubes, i, j, k, tropoinum : integer;
  plegma : array[1..100,1..100] of integer;
  tropoi : array[1..10,1..2] of integer;
  best : sindiasmos;
  x, y : sintetagmenes;
  input, output : text;

procedure compare;
var sum, i, j : integer;
begin
  sum := 0;
  for i := x[1] to y[1] do
    for j := x[2] to y[2] do
      if plegma[i,j] > 0 then
        sum := sum+1;
  if sum > best.timi then
  begin
    best.x := x;
    best.y := y;
    best.timi := sum;
    end;
  end;

BEGIN
  assign(input,'nered.in');
  reset(input);
  assign(output,'nered.out');
  rewrite(output);
  readln(input,diastaseis,cubes);
  for tropoinum := 1 to cubes do
  begin
    readln(input,i,j);
    plegma[i,j] := plegma[i,j]+1;
    end;

  tropoinum := 0;
  j := round(sqrt(cubes));
  for i := 1 to j do
    if (cubes mod i = 0) and (cubes mod i <= diastaseis) then
    begin
      tropoinum := tropoinum+1;
      tropoi[tropoinum,1] := i;
      tropoi[tropoinum,2] := cubes div i;
      end;

  best.timi := 0;
  for k := 1 to tropoinum do
  begin
    y[1] := tropoi[k,1]-1;
    for i := 1 to diastaseis-tropoi[k,1]+1 do
    begin
      x[1] := i;
      y[1] := y[1] + 1;
      y[2] := tropoi[k,2]-1;
      for j := 1 to diastaseis-tropoi[k,2]+1 do
      begin
        x[2] := j;
        y[2] := y[2]+1;
        compare;
        end;
      end;
    y[1] := tropoi[k,2]-1;
    for i := 1 to diastaseis-tropoi[k,2]+1 do
    begin
      x[1] := i;
      y[1] := y[1] + 1;
      y[2] := tropoi[k,1]-1;
      for j := 1 to diastaseis-tropoi[k,1]+1 do
      begin
        x[2] := j;
        y[2] := y[2]+1;
        compare;
        end;
      end;
    end;
  writeln (output,cubes-best.timi);
  close (output);
  close(input);
  END.

