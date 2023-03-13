#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 1. Open the file passed as an argument to the program.
//    You may assume that there will always be an argument passed
//    to the program (so you don't have to check for it).

// 2. If the file did not exists, print an appropriate message
//    and exit the program.

// 3. Create an appropriate container for tags

// 4. Go through the file, line-by-line and check for tags

// 5. Make sure that the found tag is a valid tag. A valid tag is
//    either a tag or a closing tag that contains only letters.
//    Examples of valid tags: <abc>, </ABC>
//    Examples of invalid tags: <123>, <a tag>
//    If it is invalid, print the message "Invalid tag <tag>", where
//    <tag> is replaced with the found tag, and then exit the program.

// 6. If the found tag is a normal tag, add it to the container.
//    If the found tag is a closing tag, check that it
//    matches the last added tag in the container. If not, then print
//    the error message "Tag <tag> not closed", where <tag> is
//    replaced by the last added tag in the container, and exit the
//    program.

// 7. Once the entire file has been validated, if the container is
//    empty then print the message "Valid XML file!".
//    If the container is not empty then print the message "There are
//    unclosed tags" and exit the program.
bool valid_tag(string str)
{
  for (int i = 1; i < (int)str.length() - 2; i++)
  {
    char c{str[i]};
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '/'))
    {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv)
{
  std::ifstream read_file(argv[argc - 1]);
  if (!read_file.is_open())
  {
    cerr << "ERROR: The file did not exists!" << endl;
    return -1;
  }
  vector<string> tag{};
  vector<string> xml{
      std::istream_iterator<std::string>{read_file},
      std::istream_iterator<std::string>{}};
  xml.erase(remove_if(xml.begin(), xml.end(), [](string s)
                      { return !(s[0] == '<' && s[s.length() - 1] == '>'); }),
            xml.end());
  for (auto s : xml)
  {
    if (!valid_tag(s))
    {
      cout << "Invalid tag " + s << endl;
      return 0;
    }
    else if (s[1] != '/')
    {
      tag.push_back(s);
    }
    else
    {
      std::string sample{s};
      sample.erase(1, 1);
      if (sample != tag.back())
      {
        std::cout << "Tag " << tag.back() << " not closed\n";
        return 0;
      }
      else
        tag.pop_back();
    }
  }
  if (tag.empty())
  {
    cout << "Valid XML file!" << endl;
  }
  else
  {
    cout << "There are unclosed tags" << endl;
  }
}