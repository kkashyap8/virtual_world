%% Need one input atleast : node of interest,
% Can use 2 inputs for source to sink highlight.
nodeOfInterset = inputdlg('Name the Signal/Subsystem to highlight all dependency');
PrevNode =nodeOfInterset;
tansversedPath = PrevNode;
while ~isempty(PrevNode)
   InterimNode = {};
   for i =  1:length(PrevNode)
       temp = predecessors(G,PrevNode{i});
       InterimNode(end+(1:length(temp)),1) = temp;
   end
   PrevNode(1:length(InterimNode),1) = InterimNode;
   tansversedPath(end+(1:length(InterimNode)),1) = InterimNode;
end
hold on
plot(G,tansversedPath,'dg')