PROGRAM multiplication;

VAR
  p1, p2, ginomeno, code : longint;
  a, b, number, paragontas : string[10];
  input, output : text;

procedure finish;
begin
  writeln (output,p2,' ',ginomeno);
  close (output);
  halt;
  end;

function correct : integer; {-1 = ligotera, 0 = lathos, 1 = sosto, 2 = perisotera}
var i, dval : integer; digits : array[0..9] of boolean; digit : string[1];
begin
  if length(number) < 9 then
    correct := -1
  else
    if length(number) > 9 then
      correct := 2
    else
    begin
      for i := 0 to 9 do
        digits[i] := false;
      for i := 1 to 9 do
      begin
        digit := copy(number,i,1);
        val(digit,dval,code);
        digits[dval] := true;
        end;
      correct := 1;
      if digits[0] = true then
        correct := 0
      else
        for i := 1 to 9 do
          if digits[i] = false then
            correct := 0;
      end;
  end;

BEGIN
  assign(input,'digits.in');
  reset(input);
  assign(output,'digits.out');
  rewrite(output);
  readln(input,p1);
  paragontas := '';
  repeat
    paragontas := paragontas + '9';
    val(paragontas,p2,code);
    ginomeno := p1*p2;
    str(p1,number);
    str(p2,a);
    str(ginomeno,b);
    number := number+a+b;
    until (correct = 2) or (correct = 0) or (correct = 1);
  if correct = 1 then
    finish;
  delete(paragontas,length(paragontas),1);
  val(paragontas,p2,code);
  repeat
    p2 := p2+1;
    ginomeno := p1*p2;
    str(p1,number);
    str(p2,a);
    str(ginomeno,b);
    number := number+a+b;
    until (correct = 1) or (correct = 2);
  if correct = 1 then
    finish
  else
  begin
    writeln(output,0);
    close(output);
    end;
  END.
