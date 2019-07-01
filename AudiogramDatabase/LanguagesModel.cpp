#include "LanguagesModel.h"

LanguagesModel::LanguagesModel(QString path, QObject *parent)
	: QAbstractListModel(parent)
{
	QByteArray data = QFile(path).readAll();
	QJsonDocument loadDoc = QJsonDocument::fromJson(data);
	QJsonArray array = loadDoc.array();
	elems.reserve(array.size());
	for (int i = 0; i < array.size(); ++i)
	{
		QJsonObject curObj = array[i].toObject();
		elems.emplace_back(
			curObj["code"].toString(),
			curObj["name"].toString(),
			curObj["path"].toString());
	}
}

LanguagesModel::~LanguagesModel()
{
}

int LanguagesModel::rowCount(const QModelIndex& parent) const
{
	return elems.size();
}

QVariant LanguagesModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (index.row() < 0 || elems.size() < index.row())
		return QVariant();
	const LanguageInfo& info = elems[index.row()];
	switch (role)
	{
	case NameRole: return info.name;
	case CodeRole: return info.code;
	case PathRole: return info.path;
	default: return QVariant();
	}
}

QString LanguagesModel::getPathByCode(QString code) const
{
	const int row = getRowByCode(code);
	if (row == -1)
		return QString();
	return elems[row].path;
}

int LanguagesModel::getRowByCode(QString code) const
{
	auto it = std::find_if(elems.begin(), elems.end(), [&](const LanguageInfo& elem) {
		return elem.code == code;
	});
	if (it == elems.end())
		return -1;
	return it - elems.begin();
}
