{
ID:manolis2
PROG:game1
LANG:PASCAL
}
PROGRAM newngame;

TYPE
  array2 = array[1..2] of longint;

VAR
  input, output : text;
  n, i, summation : integer;
  numbers : array[1..100] of integer;
  metriseis : array[1..5050] of array2;
  left, right, av, player : integer;

function switch(p : byte) : byte;
begin
  if p = 1 then
    switch := 2
  else
    switch := 1;
  end;

procedure nextlr;
begin
  if right+1 > n then
  begin
    av := av+1;
    left := 1;
    right := av;
    player := switch(player);
    end
  else
  begin
    left := left+1;
    right := right+1;
    end;
  end;

function lrtodec(first,last : byte) : integer;
var i : integer;
begin
  lrtodec := 1;
  for i := 1 to last-first do
    lrtodec := lrtodec+n-i+1;
  lrtodec := lrtodec+first-1;
  end;

function examine(first, last, code : integer) : array2;
var a, b : array2;
begin
  if code = 0 then
    code := lrtodec(first,last);
  if (metriseis[code,1] <> 0) or (metriseis[code,2] <> 0) then
  begin
    examine[1] := metriseis[code,1];
    examine[2] := metriseis[code,2];
    end
  else
  begin
    a := examine(first+1,last,0);
    a[player] := a[player] + numbers[first];
    b := examine(first,last-1,0);
    b[player] := b[player] + numbers[last];
    if a[player] > b[player] then
      examine := a
    else
      examine := b;
    end;
  end;

BEGIN
  assign(input,'game1.in');
  reset(input);
  assign(output,'game1.out');
  rewrite(output);
  readln(input,n);
  left := 0;
  right := n;
  av := 1;
  summation := 0;
  if n mod 2 = 1 then
    player := 1
  else
    player := 2;
  for i := 1 to n do
  begin
    read(input,numbers[i]);
    metriseis[i,player] := numbers[i];
    summation := summation+i;
    end;
  for i := n+1 to summation do
  begin
    nextlr;
    metriseis[i] := examine(left,right,i);
    end;
  writeln(output,metriseis[summation,1],' ',metriseis[summation,2]);
  close(output);
  END.
