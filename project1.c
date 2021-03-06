//Project1 creating the twitter tweeter
//first step is to parse data and place it in an array (of size 280 chars)
//second step is to use the markovian chain algorithm on the array
//markov property only depends on where i am now and not the past.
//treat every word as a state and predict the next word based on the previous state
//when a word is added, have to add one to total for that pair and add 
//one to the word appearing next based on the prev state and then divide by the 
//total to get the percentage that that word will be next
//third step is to spit out your own tweet no greater than 280 characters
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct State{
	char *prevWord;
	char *currWord;
	char *nextWord;
};
struct Word{
	int totalWords;
	int thisWord;
	int probability;
	//struct State *wordState;
	char *theCurrentWord;
};
void calcProbability(struct Word *word, struct State *wordState){
	word->probability = word->thisWord/word->totalWords;
}

//currently reads in from a file an array of words (the array with double star
//next it must go through that array and sort out next and prev words
//then move into implementing the markov chain algorithm (total number of the
//same next words/total number of next words) 
//finally must spit out the words no more than 280 chars into a new file
int main(){
	char tweetArr[280];
	//char *wordArr[280];
	char tmpArr[280];
	char *firstWord, *currentWord;
	char **words;
	FILE *tweet;
	FILE *tweetOutput;
	int index=0;
	int indexOut=0;
	int i = 0;
	int wordCount = 0;
	int wordCount2 = 0;
	struct State *wordState;
	struct Word *word;
	//struct State stateArr[280];

	//wordState = malloc(sizeof(wordState));
	//word = malloc(sizeof(word));
	tweet = fopen("/root/CPEG676/tweet.txt", "r");
	tweetOutput = fopen("/root/CPEG676/tweetOutput.txt", "w+");
	fgets(tweetArr, 280, (FILE*)tweet);
	//Gets an array of words
	
	strcpy(tmpArr, tweetArr);
	printf("\n");
	firstWord = strtok(tmpArr, " ");
	while(strtok(NULL, " ")){
		wordCount++;
	}
	
	words = malloc((wordCount+1)*sizeof(char *));
	words[wordCount] = NULL;
	wordCount2 = 0;
	firstWord = strtok(tweetArr, " ");
	words[wordCount2] = malloc(strlen(firstWord)+1);
	strcpy(words[wordCount2], firstWord);
	wordCount2 = 1;

	while(wordCount2<=wordCount){
		currentWord = strtok(NULL, " ");
		words[wordCount2] = malloc(strlen(currentWord)+1);
		strcpy(words[wordCount2], currentWord);
		wordCount2++;
	}
	
	//array of words obtained		
	for(int i=0;i<wordCount2;i++){
		printf("%s ", words[i]);
		free(words[i]);
	}
	free(words);
	
	/*
	while(index != strlen(tweetArr)){
		printf("%s", *wordArr[index]);
		if(tweetArr[index]!= ' '){
			//wordState->currWord[index] = tweetArr[index];
			
			//printf("%c", wordState->currWord);
			//wordArr[i] = wordState->currWord[index];
			//i++;
		}
		else{
			
			//could possibly make a list(maybe binsearchtree to find
			//words quickly) of Words (structs) so I can go through
			//to see if the word is already there.
			//if it is already there, look to see if it already has
			//the same previous word, if it does then change the
			//probability of the next words that could be chosen

			//I can get the next word based off the curr word 
			//obtained above and the prevWord. Using this pair,
			//I want to add the next word to have a chance of being
			//chosen after the previous two words. Here I will add
			//1 to the total words that came after the word pair, 
			//and add 1 to that word so that I can calculate the
			//chance it is chosen again
			
			
			
			//for(int ind=0;ind<strlen(wordArr);ind++){
			//	printf("%c",wordArr[i]);	
			//}
			//printf("\n");
			//calcProbability(word, wordState);

		}
		index ++;
	}
//	while(indexOut != 280){
//		if(indexOut == 0){
//
//		}
//		else{
//			//fputc(atoi(wordState->nextWord), tweetOutput);
//		}	
//		indexOut++;
//	}
	*/
	fclose(tweet);
	fclose(tweetOutput);

	return 0;
}
