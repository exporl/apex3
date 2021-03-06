function result=a3reinforcement(progressbar, feedback_len, showcurrent, showfeedback, ledfeedback)
% result=a3reinforcement(progressbar, feedback_len, showcurrent)
% if feedback_len==0 then no feedback

if (nargin<4)
    showfeedback=feedback_len~=0;
end
if (nargin<5)
    ledfeedback=0;
end

lf=sprintf('\n');
tb=sprintf('\t');
result=[ '<progressbar>' bool2xml(progressbar) '</progressbar>' lf ];
result=[result tb sprintf('<feedback length="%g">%s</feedback>\n', feedback_len, bool2xml(showfeedback)) ];
result=[result wraptag('showcurrent', bool2xml(showcurrent)) lf];
if (ledfeedback)
			result=[result '<feedbackplugin name="ledfeedback">' ...
				'<parameter name="button-90">1</parameter>' ...
				'<parameter name="button-75">2</parameter>' ...
				'<parameter name="button-60">3</parameter>' ...
				'<parameter name="button-45">4</parameter>' ...
				'<parameter name="button-30">5</parameter>' ...
				'<parameter name="button-15">6</parameter>' ...
				'<parameter name="button0">7</parameter>' ...
				'<parameter name="button15">8</parameter>' ...
				'<parameter name="button30">9</parameter>' ...
				'<parameter name="button45">10</parameter>' ...
				'<parameter name="button60">11</parameter>' ...
				'<parameter name="button75">12</parameter>' ...
				'<parameter name="button90">13</parameter>' ...
			'</feedbackplugin> ' ];
end
result=wraptag('reinforcement', result);
