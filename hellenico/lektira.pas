PROGRAM lektira;

TYPE
  string50 = string[50];

VAR
  origword, newword : string50;
  i, j, lngth : integer;
  input, output : text;
  bestword : string50;

function reverse(first,last : integer) : string50;
var i, lngth : integer; temp : char; word : string50;
begin
  lngth := last-first+1;
  word := copy(origword,first,lngth);
  for i := 1 to lngth div 2 do
  begin
    temp := word[i];
    word[i] := word[lngth-i+1];
    word[lngth-i+1] := temp;
    end;
  reverse := word;
  end;

BEGIN
  assign(input,'lektira.in');
  reset(input);
  assign(output,'lektira.out');
  rewrite(output);
  readln(input,origword);
  lngth := length(origword);
  bestword := 'zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz';
  for i := 1 to lngth-2 do
    for j := i+1 to lngth-1 do
    begin
      newword := '';
      newword := newword + reverse(1,i);
      newword := newword + reverse(i+1,j);
      newword := newword + reverse(j+1,lngth);
      if newword < bestword then
        bestword := newword;
      end;
  writeln(output,bestword);
  close(input);
  close(output);
  END.
