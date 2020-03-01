PROGRAM numtri;

VAR
  n, i, j : byte;
  numbers : array[1..100,1..100,1..2] of integer;
  input, output : text;

function best(x,y : byte) : integer;
var a,b : integer;
begin
  if x = n then
  begin
    numbers[x,y,2] := numbers[x,y,1];
    exit(numbers[x,y,1]);
    end;
  if numbers[x,y,2] <> 0 then
    exit(numbers[x,y,2]);
  a := best(x+1,y);
  b := best(x+1,y+1);
  if a > b then
  begin
    numbers[x,y,2] := a+numbers[x,y,1];
    exit(numbers[x,y,2]);
    end
  else
  begin
    numbers[x,y,2] := b+numbers[x,y,1];
    exit(numbers[x,y,2]);
    end;
  end;

BEGIN
  assign(input,'numtri.in');
  reset(input);
  assign(output,'numtri.out');
  rewrite(output);
  readln(input,n);
  for i := 1 to n do
  begin
    for j := 1 to i do
      read(input,numbers[i,j,1]);
    readln(input);
    end;
  writeln(output,best(1,1));
  close(output);
  END.