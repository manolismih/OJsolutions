PROGRAM castle;

TYPE
  enotita = record
    walls : array[1..4] of boolean;
    wallremoved : array[1..4] of integer;
    sinistosa : integer;
    end;

VAR
  input, output : text;
  n, m, i, j, rooms, max : integer;
  roomsizes : array[1..2500] of integer;
  map : array[1..50,1..50] of enotita;
  best : array[1..3] of integer;

procedure decrypt;
begin
  if rooms-8 >= 0 then
  begin
    rooms := rooms-8;
    map[i,j].walls[4] := true;
    end;

  if rooms-4 >=0 then
  begin
    rooms := rooms-4;
    map[i,j].walls[3] := true;
    end;

  if rooms-2 >= 0 then
  begin
    rooms := rooms-2;
    map[i,j].walls[2] := true;
    end;

  if rooms-1 >= 0 then
  begin
    rooms := rooms-1;
    map[i,j].walls[1] := true;
    end;
  end;

procedure floodfill(x,y : integer);
begin
  if map[x,y].sinistosa = 0 then
  begin
    map[x,y].sinistosa := rooms;
    roomsizes[rooms] := roomsizes[rooms]+1;
    if map[x,y].walls[1] = false then
      floodfill(x,y-1);
    if map[x,y].walls[2] = false then
      floodfill(x-1,y);
    if map[x,y].walls[3] = false then
      floodfill(x,y+1);
    if map[x,y].walls[4] = false then
      floodfill(x+1,y);
    end;
  end;

procedure wallremove;
begin
  if (map[i,j].walls[2] = true) and (i-1 > 0) and (map[i,j].sinistosa <> map[i-1,j].sinistosa) then
  begin
    map[i,j].wallremoved[2] := roomsizes[map[i,j].sinistosa] + roomsizes[map[i-1,j].sinistosa];
    if map[i,j].wallremoved[2] > max then
    begin
      max := map[i,j].wallremoved[2];
      best[1] := i;
      best[2] := j;
      best[3] := 2;
      end;
    end;

  if (map[i,j].walls[3] = true) and (j+1 <= m) and (map[i,j].sinistosa <> map[i,j+1].sinistosa) then
  begin
    map[i,j].wallremoved[3] := roomsizes[map[i,j].sinistosa] + roomsizes[map[i,j+1].sinistosa];
    if map[i,j].wallremoved[3] > max then
    begin
      max := map[i,j].wallremoved[3];
      best[1] := i;
      best[2] := j;
      best[3] := 3;
      end;
    end;
  end;

BEGIN
  assign(input,'castle.in');
  reset(input);
  assign(output,'castle.out');
  rewrite(output);
  readln(input,n,m);
  for i := 1 to n do
    for j := 1 to m do
    begin
      read(input,rooms);
      decrypt;
      end;

  rooms := 0;
  for i := 1 to n do
    for j := 1 to m do
      if map[i,j].sinistosa = 0 then
      begin
        rooms := rooms+1;
        floodfill(i,j);
        end;

  writeln(output,rooms);
  for i := 1 to rooms do
    if roomsizes[i] > max then
      max := roomsizes[i];
  writeln(output,max);

  max := 0;
  for j := 1 to m do
    for i := n downto 1 do
      wallremove;

  writeln(output,max);
  write(output,best[1],' ',best[2],' ');
  if best[3] = 2 then
    write(output,'N')
  else
    write(output,'E');
  close(output);
  END.
