PROGRAM trapeza;

VAR
  n, m, i, j, x, y, g, epi, max : integer;
  leptomeries : array[1..2000,1..2000] of integer;
  sindiasmos : array[1..2000] of longint;
  input, output : text;

function ekp(megalitero : longint) : longint;
var valid : boolean; k : integer;
begin
  valid := true;
  for k := 1 to leptomeries[i,2000] do
    if megalitero mod leptomeries[i,k] <> 0 then
      valid := false;
  if valid = true then
    ekp := megalitero
  else
  begin
    epi := epi+1;
    ekp := ekp((megalitero div (epi-1))*epi);
    end;
  end;

BEGIN
  assign(input,'gcrypto.in');
  reset(input);
  assign(output,'gcrypto.out');
  rewrite(output);
  readln(input,n,m);
  for i := 1 to m do
  begin
    readln(input,x,y,g);
    for j := x to y do
    begin
      leptomeries[j,2000] := leptomeries[j,2000]+1;
      leptomeries[j,leptomeries[j,2000]] := g;
      end;
    end;
  for i := 1 to n do
  begin
    max := 0;
    epi := 1;
    for j := 1 to leptomeries[i,leptomeries[i,2000]] do
      if leptomeries[i,j] > max then
        max := leptomeries[i,j];
    write(output,ekp(max),' ');
    end;
  close (output);
  end.

