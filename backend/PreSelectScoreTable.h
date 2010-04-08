#ifndef IMAGE_SEARCH_PRESELECT_SCORE_TABLE_H
#define IMAGE_SEARCH_PRESELECT_SCORE_TABLE_H

#include "ScoreTable.h"
#include <boost/serialization/base_object.hpp>

namespace boost
{
  namespace serialization
  {
    class access;
  }
}

namespace ImageSearch
{

  class PreSelectScoreTable : public ScoreTable {
  public:
    PreSelectScoreTable (int rows, int cols, int nKeptCoeffs);
    virtual ~PreSelectScoreTable (void);
  protected:
    virtual void doLoadImages (const ImageFeaturesList &images);
    virtual void doAppendImage (const ImageFeatures &image);
  private:
    PreSelectScoreTable (void);
    friend class boost::serialization::access;
    template<class Archive> void
      serialize (Archive & ar, const unsigned int version)
      {
	ar & boost::serialization::base_object<ScoreTable>(*this);
        ar & m_positiveY;
	ar & m_negativeY;
	ar & m_positiveU;
	ar & m_negativeU;
	ar & m_positiveV;
	ar & m_negativeV;
      }
    typedef std::vector<int> IdList;
    typedef IdList::iterator IdListIterator;
    typedef std::vector<IdList> IdListList;
    typedef IdListList::iterator IdListListIterator;

    virtual void p_query (ImageInformation &qY, ImageInformation &qU,
			  ImageInformation &qV, ImageScoreList &scores,
			  bool debug = false);
    void p_addImageFeatureVector (int index, const Features &src,
				  IdListList &dest);
    void p_querySingleColor (ImageInformation &truncated, ImageScoreList &scores,
			     IdListList &positives, IdListList &negatives,
			     const float weights[], bool debug = false);

    IdListList m_positiveY;
    IdListList m_negativeY;
    IdListList m_positiveU;
    IdListList m_negativeU;
    IdListList m_positiveV;
    IdListList m_negativeV;
  };

};

#endif // IMAGE_SEARCH_PRESELECT_SCORE_TABLE_H
