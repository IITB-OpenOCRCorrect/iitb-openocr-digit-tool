/*! \class Filter
 *  \brief Used to Filter file data of book projects.
 */
#include "Filters.h"
#include <string>
#include <QStringList>

/*!
 * \fn Filter::Filter
 * \brief Takes page name and extension of the pages and formats the data.
 * It sets the name of the page to variable m_name and then it takes a string (eg. jpeg;jpg;png) and splits them
 * by ";", and stores the result in a list.
 * \param const std::string & pName, const std::string & pExt
 */
Filter::Filter(const std::string & pName, const std::string & pExt) {
	m_name = m_name.fromStdString(pName);
	QString exts;
	exts = exts.fromStdString(pExt);
	QStringList list = exts.split(";");
	m_extensions = list;
}

/*!
 * \fn Filter::name
 * \brief returns the name of the page as a constant value
 * \return m_name
 */
QString Filter::name() const
{
	return m_name;
}

/*!
 * \fn Filter::name
 * \brief returns the list of the extensions as a constant value
 * \return m_extensions
 */
QStringList  Filter::extensions() const
{
	return m_extensions;
}
