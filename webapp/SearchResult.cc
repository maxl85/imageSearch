#include "SearchResult.h"

#include <Wt/WText>
#include <Wt/WImage>
#include <Wt/WAnchor>
#include <Wt/WContainerWidget>
#include <Wt/WFileResource>

#include <iostream>

using namespace ImageSearch;

SearchResult::SearchResult (Wt::WContainerWidget *parent)
  : Div ("searchResult", parent)
{
  m_imageDiv = new Div ("image", this);
  m_textDiv = new Div ("text", this);
  m_text = new Wt::WText (m_textDiv);
}

SearchResult::~SearchResult (void)
{
}

void
SearchResult::setImage (const std::string &thumbnail,
			const std::string &mimeType,
			const std::string &text,
			const std::string &anchor)
{
  m_resource = std::auto_ptr<Wt::WResource> (new Wt::WFileResource (mimeType,
								    thumbnail));
  m_text->setText (text);
  Wt::WImage *image = new Wt::WImage ();
  image->setResource (m_resource.get ());
  m_imageDiv->addWidget (new Wt::WAnchor (anchor, image));
  show ();
}

void
SearchResult::resetImage (void)
{
  hide ();
}

