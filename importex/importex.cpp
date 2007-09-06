/***** BEGIN LICENSE BLOCK *****

BSD License

Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the NIF File Format Library and Tools projectmay not be
   used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

***** END LICENCE BLOCK *****/



#include "../nifskope.h"
#include "../widgets/nifview.h"

#include <QMenu>
#include <QModelIndex>
#include <QDockWidget>


void exportObj( const NifModel * nif );
void importObj( NifModel * nif, const QModelIndex & index );

void import3ds( NifModel * nif, const QModelIndex & index );


void NifSkope::fillImportExportMenus()
{
	mExport->addAction( tr( "Export .OBJ" ) );
	mImport->addAction( tr( "Import .3DS" ) );
	mImport->addAction( tr( "Import .OBJ" ) );
}

void NifSkope::sltImportExport( QAction * a )
{
	QModelIndex index;
	/*
	As far as I can tell, this part of the code isn't working.  It's supposed
	to return the index of the currently selected object in the TreeView or
	the list view, whichever has its dock widget visible, but I can't seem to
	get any information out of the index it returns.


	if ( dList->isVisible() )
	{
		index = list->currentIndex();
	}
	else if ( dTree->isVisible() )
	{
		index = tree->currentIndex();
	}
	*/

	if ( a->text() == tr( "Export .OBJ" ) )
		exportObj( nif );
	else if ( a->text() == tr( "Import .OBJ" ) )
		importObj( nif, index );
	else if ( a->text() == tr( "Import .3DS" ) )
		import3ds( nif, index );
}
