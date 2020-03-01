PROGRAM goldbach;

VAR
  arithmos, p1, p2, num : longint;

function protos(num : longint) : boolean;

var
  i : longint;

begin
  i := 2;
  while (i < num) and (num mod i > 0) do
  i := i + 1;
  if i = num then
    protos := true
  else protos := false;
end;

function findnextnum : longint;

begin
  repeat
  num := num + 1;
  until protos(num) = true;
  findnextnum := num;
end;

BEGIN
  num := 1;
  assign (input,'goldbach.in');
  assign (output,'goldbach.out');
  reset (input);
  rewrite (output);
  read (input, arithmos);
  repeat
  p1 := findnextnum;
  if protos(arithmos-p1) = true then
    begin
    p2 := arithmos-p1;
    write (output,p1,' ',p2);
    close (input);
    close (output);
    halt(0);
    end;
  until 0 = 1;
end.


