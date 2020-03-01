program brokenwatch;

var
  mychar : char;
  hh, mm, ss, kratoumeno, i : integer;
  input, output : text;
begin
  assign (input, 'time.in');
  assign (output, 'time.out');
  reset (input);
  rewrite (output);
  read (input, mychar);
  case mychar of
  '1': hh := hh+10;
  '2': hh := hh+20;
  '3': hh := hh+30;
  '4': hh := hh+40;
  '5': hh := hh+50;
  end;
  read (input, mychar);
  case mychar of
  '1': hh := hh+1;
  '2': hh := hh+2;
  '3': hh := hh+3;
  '4': hh := hh+4;
  '5': hh := hh+5;
  '6': hh := hh+6;
  '7': hh := hh+7;
  '8': hh := hh+8;
  '9': hh := hh+9;
  end;
  read (input, mychar);
  read (input, mychar);
  case mychar of
  '1': mm := mm+10;
  '2': mm := mm+20;
  '3': mm := mm+30;
  '4': mm := mm+40;
  '5': mm := mm+50;
  end;
  read (input, mychar);
  case mychar of
  '1': mm := mm+1;
  '2': mm := mm+2;
  '3': mm := mm+3;
  '4': mm := mm+4;
  '5': mm := mm+5;
  '6': mm := mm+6;
  '7': mm := mm+7;
  '8': mm := mm+8;
  '9': mm := mm+9;
  end;
  read (input, mychar);
  read (input, mychar);
  case mychar of
  '1': ss := ss+10;
  '2': ss := ss+20;
  '3': ss := ss+30;
  '4': ss := ss+40;
  '5': ss := ss+50;
  end;
  read (input, mychar);
  case mychar of
  '1': ss := ss+1;
  '2': ss := ss+2;
  '3': ss := ss+3;
  '4': ss := ss+4;
  '5': ss := ss+5;
  '6': ss := ss+6;
  '7': ss := ss+7;
  '8': ss := ss+8;
  '9': ss := ss+9;
  end;
  hh := hh*2;
  mm := mm*2;
  ss := ss*2;
  if ss >= 60 then
    begin
    kratoumeno := ss div 60;
    ss := ss mod 60;
    end;
  mm := mm+kratoumeno;
  kratoumeno := 0;
  if mm >= 60 then
    begin
    kratoumeno := mm div 60;
    mm := mm mod 60;
    end;
    hh := hh+kratoumeno;
    if hh < 10 then
    write (output, 0, hh)
    else write (output, hh);
    write (output, ':');
    if mm < 10 then
    write (output, 0, mm)
    else write (output, mm);
    write (output, ':');
    if ss < 10 then
    write (output, 0, ss)
    else write (output, ss);
    close (input);
    close (output);
end.