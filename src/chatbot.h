#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned) 
    
    // Dear Reviewer: what does this mean?
    // Does this mean that the memory for "not owned" variables is not allocated by the constructor of this class?
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic; // Dear Reviewer: Why is this actually allowed even though chatgui.h declared it as a unique pointer?

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot(); //1. Destructor

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot &source); //2. Copy Constructor
    ChatBot &operator=(const ChatBot &source); //3. Copy Assignment Operator;
    ChatBot(ChatBot &&source); //4. Move Constructor
    ChatBot &operator=(ChatBot &&source); // Move Assignment Operator;
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
