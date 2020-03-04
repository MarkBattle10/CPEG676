//Project1 creating the twitter tweeter
//first step is to parse data and place it in an array (of size 280 chars)
//second step is to use the markovian chain algorithm on the array
//markov property only depends on where i am now and not the past.
//treat every word as a state and predict the next word based on the previous state
//when a word is added, have to add one to total for that pair and add 
//one to the word appearing next based on the prev state and then divide by the 
//total to get the percentage that that word will be next
//third step is to spit out your own tweet no greater than 280 characters


#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <time.h>
using namespace std;


int main(){
	//typedef vector<string> vecString;
  srand(time(NULL));
	
	multimap<pair<string,string>, pair<string,double>> markovMMap;
	//multimap<strPair, string> markovMMap;
	int i=0;
	//vector<string> tweetVect;
	string tweetArr[280];
	ifstream file;
	ofstream outFile;
	file.open("tweet2.txt");

	while(file){
		file >> tweetArr[i];
		if(i>1){
			markovMMap.insert(make_pair(make_pair(tweetArr[i-2],tweetArr[i-1]),make_pair(tweetArr[i],0)));

		}
		else if(i==1){
			markovMMap.insert(make_pair(make_pair("empty",tweetArr[i-1]),make_pair(tweetArr[i],0)));
		
		}
		else{
			markovMMap.insert(make_pair(make_pair("empty","empty"),make_pair(tweetArr[i],0)));
	
		}
		i++;
	}

	multimap<pair<string,string>,pair<string,double>>::iterator iter1;
	multimap<pair<string,string>,pair<string,double>>::iterator iter2;
	
	int countArr[markovMMap.size()];
	int index = 0;
	int totalCount;
	for(iter1 = markovMMap.begin(); iter1 != markovMMap.end(); ++iter1){
		totalCount = 0;
		for(iter2 = markovMMap.begin(); iter2 != markovMMap.end(); ++iter2){
			//if(iter2 != iter1){
				if((iter2->first.first == iter1->first.first) && (iter2->first.second == iter1->first.second)){
          if(iter2->second.first == iter1->second.first){
            iter2->second.second = iter2->second.second +1;

          }
          totalCount = totalCount+1;
				}
        
        
				//iter2->second.second = iter2->second.second + 1;
        //totalCount = totalCount+1;
			//}
			
		}
		countArr[index] = totalCount;
		index = index+1;
	}
	
	index = 0;
	for(iter1 = markovMMap.begin(); iter1 != markovMMap.end(); ++iter1){
    //cout<< countArr[index]<< " ";
		if(iter1->second.second != 0){
			iter1->second.second = (iter1->second.second)/(countArr[index]);	
		}
		index = index+1;
	}	
	
	outFile.open("tweetOut2.txt");	
	
	multimap<pair<string,string>,pair<string,double>>::iterator iter;

  
  
  //dene's attempt
  int charCount = 0;
  vector<string> wordTracker; //to keep track of the words placed into our tweet
  int wordTrackerIndex = 0;

  pair<multimap<pair<string,string>,pair<string,double>>::iterator, multimap<pair<string,string>,pair<string,double>>::iterator> result = markovMMap.equal_range(pair<string,string> ("empty","empty"));

  vector<string> randProbWord;
  i = 0;
  for(iter = result.first; iter != result.second; ++iter){
    randProbWord.push_back(iter->second.first);
    //cout << randProbWord[i] << endl;
    i++;
  }	
  //cout << randProbWord.size() << endl;  
  int randIndex = rand()%randProbWord.size();
  //cout << randIndex << endl;
  cout << randProbWord[randIndex] << endl;
  charCount = randProbWord[randIndex].length() + 1; //the plus one is to account for the spaces
  cout << charCount << endl;
  wordTracker.push_back(randProbWord[randIndex]);

  while(!randProbWord.empty()){
    randProbWord.pop_back();
  }

  
  result = markovMMap.equal_range(pair<string,string> ("empty",wordTrackerIndex[0]));

  i = 0;
  for(iter = result.first; iter != result.second; ++iter){
    randProbWord.push_back(iter->second.first);
    //cout << randProbWord[i] << endl;
    i++;
  }	
  //cout << randProbWord.size() << endl;  
  randIndex = rand()%randProbWord.size();
  //cout << randIndex << endl;
  cout << randProbWord[randIndex] << endl;
  charCount = randProbWord[randIndex].length() + 1; 
  cout << charCount << endl;
  wordTracker.push_back(randProbWord[randIndex]);
  wordTrackerIndex += 1;
  
  while(charCount < 280){
    result = markovMMap.equal_range(pair<string,string> ("empty",wordTrackerIndex[0]));

    i = 0;
    for(iter = result.first; iter != result.second; ++iter){
      randProbWord.push_back(iter->second.first);
      //cout << randProbWord[i] << endl;
      i++;
    }	
    //cout << randProbWord.size() << endl;  
    randIndex = rand()%randProbWord.size();
    //cout << randIndex << endl;
    cout << randProbWord[randIndex] << endl;
    charCount = randProbWord[randIndex].length() + 1; 
    cout << charCount << endl;
    wordTracker.push_back(randProbWord[randIndex]);
    wordTrackerIndex += 1;
    
  }
  
  




  //empty empty

	for(iter = markovMMap.begin(); iter != markovMMap.end(); ++iter){
		outFile << iter->first.first << " " << iter->first.second << " " << iter->second.first << " " << iter->second.second << endl;
	}

	return 0;

}
