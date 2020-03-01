program enudrio;

const
  isitirio = 10;

var
  kostologio : array[1..3,1..5] of longint;
  atoma : integer;
  simftimi, i : longint;
  category : 1..5;
  input, output : text;

begin
  simftimi := 100000;
  assign (input, 'tickets.in');
  assign (output, 'tickets.out');
  reset (input);
  rewrite (output);
  kostologio[1,1] :=0;
  readln (input, atoma);
  for i := 2 to 5 do
    read (input, kostologio[1,i]);
  kostologio[2,1] := 0;
  kostologio[2,2] := 10;
  kostologio[2,3] := 20;
  kostologio[2,4] := 30;
  kostologio[2,5] := 50;
    if atoma >= kostologio[1,2] then
      if atoma >= kostologio[1,3] then
        if atoma >= kostologio[1,4] then
          if atoma >= kostologio[1,5] then
            category := 5
          else category := 4
        else category := 3
      else category := 2
    else category := 1;
  kostologio[3,category] := atoma*isitirio-atoma*isitirio*kostologio[2,category] div 100;
  for i := category+1 to 5 do
    kostologio[3,i] := kostologio[1,i]*isitirio-kostologio[1,i]*isitirio*kostologio[2,i] div 100;
  for i := category to 5 do
    if kostologio[3,i] < simftimi then
      simftimi := kostologio[3,i];
  write (output, simftimi);
  close (input);
  close (output);
  end.
