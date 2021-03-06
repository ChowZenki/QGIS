/***************************************************************************
    qgsfontutils.h
    ---------------------
    begin                : June 5, 2013
    copyright            : (C) 2013 by Larry Shaffer
    email                : larrys at dakotacarto dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSFONTUTILS_H
#define QGSFONTUTILS_H

#include <QFont>
#include <QString>

class CORE_EXPORT QgsFontUtils
{
  public:
    /** Check whether exact font is on system
     * @param f The font to test for match
     */
    static bool fontMatchOnSystem( const QFont& f );

    /** Check whether font family is on system in a quick manner, which does not compare [foundry]
     * @param family The family to test
     * @returns Whether family was found on system
     * @note This is good for use in loops of large lists, e.g. registering many features for labeling
     */
    static bool fontFamilyOnSystem( const QString& family );

    /** Check whether font family is on system
     * @param family The family to test
     * @param chosen The actual family (possibly from different foundry) returned by system
     * @param match Whether the family [foundry] returned by system is a match
     * @returns Whether family was found on system
     */
    static bool fontFamilyMatchOnSystem( const QString& family, QString* chosen = 0, bool* match = 0 );

    /** Updates font with named style and retain all font properties
     * @param f The font to update
     * @param fontstyle The style to try and switch the font to
     * @param fallback If no matching fontstyle found for font, assign most similar or first style found to font
     * @returns Whether the font was updated (also returns true if the requested style matches font's current style)
     * @note This is a more featured replacement for a Qt 4.8+ function: void QFont::setStyleName ( const QString & styleName )
     */
    static bool updateFontViaStyle( QFont& f, const QString& fontstyle, bool fallback = false );

};

#endif // QGSFONTUTILS_H
