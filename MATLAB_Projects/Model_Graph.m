%%% #TODO List
% #. Include Virtual, atomic subsystem, libraray link,reference
% model,protected model, SIL subsystem as well.
% 1. Architecure Depth(Subsystem Level till contamination)
% 2. list of each layer with subsystem with I/O ratio & coupling at that
% layer and above
% 3. Detailing degree at each layer, ex. top layer should have bus and
% inner most layer must have signal connected.
% 4. ISO 26262 checks 
% 5. color coding for different types in reports.
% 6. Unit scheduling,Subsystem scheduling list.
% 7. Parameter list and degree of scattereness.

[model,Path] = uigetfile('*.slx','Please select Lib for analysis');
h_model = load_system([Path,model(1:end-4)]);
subsystem = find_system(get(h_model,'Name'),'SearchDepth',1,'BlockType','SubSystem');
nodeDef = {};
nodeType = {};
for i = 1:length(subsystem)
    inports = find_system(subsystem{i},'SearchDepth',1,'BlockType','Inport');
    inportsName = get_param(inports,'Name');
    Outports = find_system(subsystem{i},'SearchDepth',1,'BlockType','Outport');
    OutportsName = get_param(Outports,'Name');
    nodeDef = [nodeDef,[[inportsName';repmat(get_param(subsystem(i),'Name'),1,length(inportsName))],[repmat(get_param(subsystem(i),'Name'),1,length(OutportsName));OutportsName']]];
    %nodeType = [nodeType,[repmat('Input',1,length(inportsName)),repmat('Unit System',1,length(inportsName))]];
end
G = digraph(nodeDef(1,:),nodeDef(2,:));
%G.Nodes.Type = nodeType;
%plot(G,'Layout','layered')
h = plot(G,'Layout','layered');
set(h,'MarkerSize',10);
set(h,'EdgeColor',[1,0,0]);
h.NodeCData = ismember(h.NodeLabel,'LaneGuidanceAlgorithm');
temp = getframe(gcf);
imwrite(temp.cdata,'tree.jpeg');
%%% Write in excel and format cell correctly
excel = actxserver('Excel.Application');  
excelWorkbook = excel.Workbooks.Add(1);   
excelSheet = excel.ActiveSheet; 
excel.Visible = 1;
excelSheet.set('Name','Dependency Matrix');
eActivesheetRange = get(excel.Activesheet,'Range','A1:A1');
eActivesheetRange.Value = 'Dependency Matrix';
eActivesheetRange.Interior.ColorIndex = 17;
eActivesheetRange.Borders.LineStyle = 1;
eActivesheetRange.Font.Bold = 1;
eActivesheetRange.Font.Size = 16;
eActivesheetRange.HorizontalAlignment = 3;
eActivesheetRange.VerticalAlignment  = 2; 
eActivesheetRange.Orientation = 0;
count = height(G.Nodes);
row = num2str(count+1);
col = char(64+count+1);
eActivesheetRange = get(excel.Activesheet,'Range',['A2:A',row]);
eActivesheetRange.Value = G.Nodes.Name;
eActivesheetRange.RowHeight = 25;
eActivesheetRange.ColumnWidth = 30;
eActivesheetRange.Interior.ColorIndex = 19;
eActivesheetRange.Borders.LineStyle = 1;
eActivesheetRange.Font.Bold = 1;
eActivesheetRange.HorizontalAlignment = 3;
eActivesheetRange.VerticalAlignment  = 2; 
eActivesheetRange.Cells.ShrinkToFit = 1;
eActivesheetRange.Orientation = 0;
eActivesheetRange = get(excel.Activesheet,'Range',['B1:',col,'1']);
eActivesheetRange.Value = G.Nodes.Name';
eActivesheetRange.RowHeight = 150;
eActivesheetRange.ColumnWidth = 5;
eActivesheetRange.Interior.ColorIndex = 19;
eActivesheetRange.Borders.LineStyle = 1;
eActivesheetRange.Font.Bold = 1;
eActivesheetRange.HorizontalAlignment = 3;
eActivesheetRange.VerticalAlignment  = 2; 
eActivesheetRange.Cells.ShrinkToFit = 1;
eActivesheetRange.Orientation = 90;
eActivesheetRange = get(excel.Activesheet,'Range',['B2:',col,row]);
eActivesheetRange.Value = full(G.adjacency);
eActivesheetRange.Borders.LineStyle = 1;
eActivesheetRange.HorizontalAlignment = 3;
eActivesheetRange.VerticalAlignment  = 2;
eActivesheetRange.FormatConditions.AddColorScale(2);
excelSheet = excelWorkbook.Sheets.Add();
excelSheet.Activate
excelSheet.set('Name','Dependency Tree');
eActivesheetRange = get(excel.Activesheet,'Range','A1:A2');
excelSheet.Shapes.AddPicture([Path,'tree.jpeg'], true, true, 0, 0,640,480);
invoke(excelWorkbook,'SaveAs',[Path,'Dependency Report.xlsx']);
invoke(excel,'Quit');
delete(excel);
delete('tree.jpeg');

