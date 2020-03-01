PROGRAM trenaki;
VAR
  n, k, i, x, t, teleutaio, megalitero : longint;
  ebodia : array[1..1000000] of longint;
  xronoi : array of boolean;
  inout, output : text;

BEGIN
  assign(input,'horror.in');
  reset(input);
  assign(output,'horror.out');
  rewrite(output);
  readln(input,n,k);
  megalitero := 0;
  for i := 1 to n do
  begin
    readln(input,x,t);
    ebodia[x] := t;
    if t > megalitero then
      setlength(xronoi,t+1);
    xronoi[t] := true;
    end;
  teleutaio := x;
  x := 0;
  t := 0;
  repeat
    x := x+1;
    t := t+1;
    while t < ebodia[x] do
      begin
        k := k-1;
        t := t+1;
        end;
    if k < 0 then
      begin
        writeln(output,x);
        close(output);
        halt;
        end;
    until x = teleutaio;
  writeln(output,-1);
  close(output);
  end.
