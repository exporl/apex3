/******************************************************************************
 * Copyright (C) 2008  Tom Francart <tom.francart@med.kuleuven.be>            *
 *                                                                            *
 * This file is part of APEX 3.                                               *
 *                                                                            *
 * APEX 3 is free software: you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * APEX 3 is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with APEX 3.  If not, see <http://www.gnu.org/licenses/>.            *
 *****************************************************************************/
 
#ifndef RUNDELEGATECREATORVISITOR_H
#define RUNDELEGATECREATORVISITOR_H

#include "screen/screenelementvisitor.h"
#include "rundelegatedefines.h"

#include <QFont>

namespace apex
{
    class ExperimentRunDelegate;
namespace rundelegates
{
using data::ScreenElementVisitor;
using data::AnswerLabelElement;
using data::ArcLayoutElement;
using data::ButtonElement;
using data::EmptyElement;
using data::FlashPlayerElement;
using data::GridLayoutElement;
using data::LabelElement;
using data::ParameterListElement;
using data::ParameterLabelElement;
using data::PictureElement;
using data::PictureLabelElement;
using data::TextEditElement;
using data::SpinBoxElement;
using data::SliderElement;
using data::CheckBoxElement;
using data::MatrixElement;

/**
 * The RunDelegateCreatorVisitor class is a class that is used to
 * create a ScreenElementRunDelegate for a given ScreenElement.  I
 * did not name it ScreenElementRunDelegateCreatorVisitor for
 * brevity ;)
 *
 * It is an implementation of the ScreenElementVisitor class in
 * order to avoid having a big ugly switch in the code...
 */
class RunDelegateCreatorVisitor
            : public ScreenElementVisitor
{
    QWidget* parent;
    elementToRunningMapT& elementToRunningMap;
    QFont defaultFont;
    ScreenElementRunDelegate* lastcreated;
public:
    RunDelegateCreatorVisitor(
        ExperimentRunDelegate* p_exprd,
        QWidget* parent,
        elementToRunningMapT& elementToRunningMap,
        const QFont& defaultFont);

    ScreenElementRunDelegate* createRunDelegate(const ScreenElement* e);
    ~RunDelegateCreatorVisitor();

private:
    void visitAnswerLabel(const AnswerLabelElement* e);
    void visitArcLayout(const ArcLayoutElement* e);
    void visitButton(const ButtonElement* e);
    void visitMatrix(const MatrixElement* e);
    void visitSpinBox(const SpinBoxElement* e);
    void visitSlider(const SliderElement* e);
    void visitCheckBox(const CheckBoxElement* e);
    void visitEmpty(const EmptyElement* e);
    void visitFlashPlayer(const FlashPlayerElement* e);
    void visitGridLayout(const GridLayoutElement* e);
    void visitLabel(const LabelElement* e);
    void visitParameterList(const ParameterListElement* e);
    void visitParameterLabel(const ParameterLabelElement* e);
    void visitPicture(const PictureElement* e);
    void visitPictureLabel(const PictureLabelElement* e);
    void visitTextEdit(const TextEditElement* e);

    ExperimentRunDelegate* m_rd;
};
}
}

#endif