PROGRAM corners;
TYPE
  thesi = record
    pawns : array[1..4] of byte;
    moves : byte;
    next : pointer;
    end;
  pointer = ^thesi;
  array36 = array[1..6,1..6] of boolean;
  code = array[1..8] of shortint;

VAR
  input, output : text;
  i, j : shortint;
  pista : array[0..7,0..7] of char;
  checked : array[1..6,1..6,1..6,1..6,1..6,1..6,1..6,1..6] of boolean;
  correct : code;
  head, tail, node : pointer;
  kiniseis : array[1..4] of shortint;
  falsearray : array36;

procedure examine;

        procedure addtoqueue(t : byte);
        var k, l, temp : byte; newpawns : array[1..4] of byte;
        begin
          newpawns := head^.pawns;
          newpawns[i] := newpawns[i] + t*kiniseis[j];

          if kiniseis[j] > 0 then
          begin
            k := i;
            while (k+1 <= 4) and (newpawns[k] > newpawns[k+1]) do
            begin
              temp := newpawns[k];
              newpawns[k] := newpawns[k+1];
              newpawns[k+1] := temp;
              k := k+1;
              end;
            end
          else
          begin
            k := i;
            while (k-1 >= 1) and (newpawns[k] < newpawns[k-1]) do
            begin
              temp := newpawns[k];
              newpawns[k] := newpawns[k-1];
              newpawns[k-1] := temp;
              k := k-1;
              end;
            end;

          if (newpawns[1] div 10 = 1) and (newpawns[1] mod 10 = 1) and (newpawns[2] div 10 = 1) and (newpawns[2] mod 10 = 2) and (newpawns[3] div 10 = 2) and (newpawns[3] mod 10 = 1) and (newpawns[4] div 10 = 2) and (newpawns[4] mod 10 = 2) then
          begin
            writeln(output,head^.moves+1);
            close(output);
            halt;
            end;

          if checked[newpawns[1] div 10,newpawns[1] mod 10,newpawns[2] div 10,newpawns[2] mod 10,newpawns[3] div 10,newpawns[3] mod 10,newpawns[4] div 10,newpawns[4] mod 10] then
            exit;

          checked[newpawns[1] div 10,newpawns[1] mod 10,newpawns[2] div 10,newpawns[2] mod 10,newpawns[3] div 10,newpawns[3] mod 10,newpawns[4] div 10,newpawns[4] mod 10] := true;
          new(node);
          tail^.next := node;
          tail := node;
          node^.pawns := newpawns;
          node^.moves := head^.moves+1;
          end;

        function blank(square : byte) : boolean;
        begin
          if (pista[square div 10,square mod 10] = '.') and (head^.pawns[1] <> square) and (head^.pawns[2] <> square) and (head^.pawns[3] <> square) and (head^.pawns[4] <> square) then
            exit(true)
          else
            exit(false);
          end;

begin
  for i := 1 to 4 do
    for j := 1 to 4 do
      if blank(head^.pawns[i]+kiniseis[j]) then
        addtoqueue(1)
      else
        if pista[(head^.pawns[i]+kiniseis[j]) div 10,(head^.pawns[i]+kiniseis[j]) mod 10] <> 'r' then
          if blank(head^.pawns[i]+kiniseis[j]*2) then
            addtoqueue(2);
  end;



function check(x,y : shortint; poreia : array36) : boolean;
begin
  if (x = 1) and (y = 1) then
    exit(true);
  if (pista[x,y] <> '.') or poreia[x,y] then
    exit(false);
  poreia[x,y] := true;
  check := false;

  if (pista[x-1,y] = 's') and (pista[x-2,y] = '.') then
    check := check(x-2,y,poreia)
  else
    check := check(x-1,y,poreia);
  if check then
    exit(true);

  if (pista[x,y-1] = 's') and (pista[x,y-2] = '.') then
    check := check(x,y-2,poreia)
  else
    check := check(x,y-1,poreia);
  if check then
    exit(true);

  if (pista[x+1,y] = 's') and (pista[x+2,y] = '.') then
    check := check(x+2,y,poreia)
  else
    check := check(x+1,y,poreia);
  if check then
    exit(true);

  if (pista[x,y+1] = 's') and (pista[x,y+2] = '.') then
    check := check(x,y+2,poreia)
  else
    check := check(x,y+1,poreia);
  end;

BEGIN
  assign(input,'corners.in');
  reset(input);
  assign(output,'corners.out');
  rewrite(output);
  for j := 0 to 7 do
    pista[i,j] := 'r';
  i := 7;
  for j := 0 to 7 do
    pista[i,j] := 'r';
  for i := 1 to 6 do
    pista[i,j] := 'r';
  j := 0;
  for i := 1 to 6 do
    pista[i,j] := 'r';
  kiniseis[1] := 1;
  kiniseis[2] := 10;
  kiniseis[3] := -1;
  kiniseis[4] := -10;
  correct[1] := 1;
  correct[2] := 1;
  correct[3] := 1;
  correct[4] := 2;
  correct[5] := 2;
  correct[6] := 1;
  correct[7] := 2;
  correct[8] := 2;

  for i := 1 to 6 do
  begin
    for j := 1 to 6 do
      read(input,pista[i,j]);
    readln(input);
    end;
  if (pista[1,1] <> '.') or (pista[1,2] <> '.') or (pista[2,1] <> '.') or (pista[2,2] <> '.') or (check(5,5,falsearray) = false) then
  begin
    writeln(output,-1);
    close(output);
    halt;
    end;

  new(head);
  tail := head;
  with head^ do
  begin
    pawns[1] := 55;
    pawns[2] := 56;
    pawns[3] := 65;
    pawns[4] := 66;
    moves := 0;
    end;

  while head <> nil do
  begin
    examine;
    node := head;
    head := head^.next;
    dispose(node);
    end;
  END.
