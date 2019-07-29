#include "ColorPicker.h"

ColorPicker::ColorPicker(QWidget *parent, QColor color)
	: QWidget(parent), color(color)
{
	colorLabel = new QLabel;
	changePB = new QPushButton(tr("Change"));

	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(colorLabel);
	layout->addWidget(changePB);
	setLayout(layout);

	connect(changePB, &QPushButton::clicked, this, &ColorPicker::sColorDialog);
}

ColorPicker::~ColorPicker()
{
}

void ColorPicker::resizeEvent(QResizeEvent* event)
{
	updateLabel();
}

void ColorPicker::updateLabel()
{
	QPixmap colorIcon(32, 32);
	colorIcon.fill(color);
	colorLabel->setPixmap(colorIcon.scaled(colorLabel->size(), Qt::KeepAspectRatio));
}

void ColorPicker::sColorDialog(void)
{
	color = QColorDialog::getColor(color, this);
	updateLabel();
}
