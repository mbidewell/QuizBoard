var gCurrQuestion = null;
var gQuestions = null;

jQuery.fn.center = function () {
    this.css("position","absolute");
    this.css("top", Math.max(0, (($(window).height() - $(this).outerHeight()) / 2) + 
                                                $(window).scrollTop()) + "px");
    this.css("left", Math.max(0, (($(window).width() - $(this).outerWidth()) / 2) + 
                                                $(window).scrollLeft()) + "px");
    return this;
}

function getQuiz() {
	$.getJSON("http://localhost:8000/quiz.json", function(quiz){
		categories = quiz["categories"];
		gQuestions= quiz["questions"]
		
		for(i=0; i < categories.length; i++) {
			var id = "#header_c" + (i+1);
			$(id).text(categories[i]);
		}
		
	});
}

/*
 * Initialize Page.  
 */


$(function() {
	var $questionDiv = $("#questionContainer");
	$questionDiv.hide();
	
	getQuiz();

	$(".unanswered").click(function() {
		var $questionDiv = $("#questionContainer");
		var $question = $("#question");
		if(gQuestions[this.id] != null) {
			$question.text(gQuestions[this.id]);	
		} else {
			$question.text(this.id);
		}
		gCurrQuestion = this;
		$questionDiv.center();
		$questionDiv.show();
	});
	$("#correct").click(function() {
		var $questionDiv = $("#questionContainer");
		$questionDiv.hide();
		$(gCurrQuestion).off("click");
		$(gCurrQuestion).text("");
	});	
	$("#incorrect").click(function() {
		var $questionDiv = $("#questionContainer");
		$questionDiv.hide();
	});					
});