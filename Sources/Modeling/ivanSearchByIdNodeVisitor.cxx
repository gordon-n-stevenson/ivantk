/*=========================================================================

Image-based Vascular Analysis Toolkit (IVAN)

Copyright (c) 2012, Iván Macía Oliver
Vicomtech Foundation, San Sebastián - Donostia (Spain)
University of the Basque Country, San Sebastián - Donostia (Spain)

All rights reserved

See LICENSE file for license details

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
SUCH DAMAGE.

==========================================================================*/
// File: ivanSearchByIdNodeVisitor.cxx
// Author: Iv�n Mac�a (imacia@vicomtech.org)
// Description:
// Date: 2010/07/29


#include "ivanSearchByIdNodeVisitor.h"


namespace ivan
{
  
SearchByIdNodeVisitor::SearchByIdNodeVisitor() :
  m_NodeId(0)
{
  this->AddDispatcher<Self,GraphNode>();
}


SearchByIdNodeVisitor::~SearchByIdNodeVisitor()
{

}


void SearchByIdNodeVisitor::Apply( GraphNode * node )
{
  if( node->GetNodeId() == m_NodeId )
    m_Node = node;
  else
    this->Traverse( node ); // continue with traversal
}


void SearchByIdNodeVisitor::PrintSelf( std::ostream& os, itk::Indent indent ) const
{
  Superclass::PrintSelf( os, indent );
  
  os << indent << "NodeId: " << m_NodeId << std::endl;
  os << indent << "Node: " << m_Node.GetPointer() << std::endl;
  m_Node->Print( os, indent.GetNextIndent() );
}

} // end namespace ivan

