#ifndef SEARCH_RESULT_H
#define SEARCH_RESULT_H

#include <string>

namespace Wt
{
  class WContainerWidget;
  class WImage;
  class WText;
  class WAnchor;
};

namespace ImageSearch
{
  class Div;
  class SearchResult
  {
  public:
    SearchResult (Wt::WContainerWidget *parent);
    virtual ~SearchResult (void);
    void setImage (const std::string &thumbnail,
		   const std::string &mimeType,
		   const std::string &text,
		   const std::string &anchor);
    void resetImage (void);
  private:
    Div *m_container;
    Wt::WImage *m_image;
    Wt::WText *m_text;
    Wt::WAnchor *m_anchor;
  };
};

#endif // SEARCH_RESULT_H
