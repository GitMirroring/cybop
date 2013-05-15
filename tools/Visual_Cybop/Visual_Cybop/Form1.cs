using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Visual_Cybop
{
    public partial class frm_Main : Form
    {
        public frm_Main()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Event zum Zeichnen der Knoten, 
        /// damit die Hintergrundfarbe blau bleibt wenn der Selektierte Knoten den Focus verliert
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tree_Model_DrawNode(object sender, DrawTreeNodeEventArgs e)
        {
            Font f = e.Node.NodeFont != null ? e.Node.NodeFont : e.Node.TreeView.Font;
            Size sz = TextRenderer.MeasureText(e.Node.Text, f);
            Rectangle rc = new Rectangle(e.Bounds.X - 1, e.Bounds.Y, sz.Width + 2, e.Bounds.Height);
            Color fore = e.Node.ForeColor;
            if (fore == Color.Empty) fore = e.Node.TreeView.ForeColor;
            if (e.Node == e.Node.TreeView.SelectedNode)
            {
                fore = SystemColors.HighlightText;
                if ((e.State & TreeNodeStates.Focused) != 0)
                {
                    fore = SystemColors.WindowText;
                }
            }
            Color back = e.Node.BackColor;
            if (back == Color.Empty) back = e.Node.TreeView.BackColor;
            if (e.Node == e.Node.TreeView.SelectedNode)
            {
                back = SystemColors.Highlight;
                fore = SystemColors.HighlightText;
            }
            SolidBrush bbr = new SolidBrush(back);
            e.Graphics.FillRectangle(bbr, rc);
            TextRenderer.DrawText(e.Graphics, e.Node.Text, f, rc, fore, TextFormatFlags.GlyphOverhangPadding);
            bbr.Dispose();
        }

        /// <summary>
        /// Menü - Datei -> Beenden
        /// </summary>
        private void beendenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit(null);
        }

        private void frm_Main_Shown(object sender, EventArgs e)
        {

            //dataset_Main.PropertiesRow proprow = dataset_Main.Properties.NewPropertiesRow();
            //proprow.Node_Id = 1;
            //proprow.Name = "Test";
            //proprow.Channel = "inline";
            //proprow.Format = "plain/text";

            //dataset_Main.Properties.Rows.Add(proprow);
        }

        /// <summary>
        /// Fügt dem aktuellen Pfad im Baum einen Knoten hinzu
        /// </summary>
        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            TreeNode node = new TreeNode("NewPart");
            node.Tag = -1;
            if (tree_Model.SelectedNode.Parent == null)
            {
                tree_Model.SelectedNode.Nodes.Add(node);
                node.Tag = InsertNodeRow(node.Text, GetNodeIndexPath(node));
            }
            else
            {
                int id = Convert.ToInt32(tree_Model.SelectedNode.Parent.Tag);
                tree_Model.SelectedNode.Parent.Nodes.Add(node);
                if (Convert.ToInt32(tree_Model.SelectedNode.Parent.Tag) == 0)
                    node.Tag = InsertNodeRow(node.Text, GetNodeIndexPath(node));                    
                else
                    node.Tag = InsertNodeRow(node.Text, id, GetNodeIndexPath(node));
            }
            node.Parent.Expand();

            tree_Model.SelectedNode = node;
        }

        /// <summary>
        /// Fügt dem aktuell selektierten Knoten einen Unterknoten hinzu
        /// </summary>
        private void btn_AddSub_Click(object sender, EventArgs e)
        {
            TreeNode node = new TreeNode("NewPart");
            node.Tag = -1;
            int id = Convert.ToInt32(tree_Model.SelectedNode.Tag);
            tree_Model.SelectedNode.Nodes.Add(node);
            tree_Model.SelectedNode.Expand();
            node.Tag = InsertNodeRow(node.Text, id, GetNodeIndexPath(node));
            UpdateNodeRow(id, null, null, "file", "element/part", tree_Model.SelectedNode.Text, null);

            tree_Model.SelectedNode = node;
        }

        private void btn_DelNode_Click(object sender, EventArgs e)
        {
            if (tree_Model.SelectedNode.Parent == null)
            {
                MessageBox.Show("Der Hauptknoten kann nicht entfernt werden", "Operation nicht erlaubt.", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
            else if (MessageBox.Show("Sind Sie sicher, dass Sie den aktuellen Part, inklusive aller Unterparts, entfernen wollen?", "Wirklich entfernen?", MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.Yes)
            {
                int id = Convert.ToInt32(tree_Model.SelectedNode.Tag);
                if (DeleteNodeRow(id))
                    tree_Model.SelectedNode.Remove();
                else
                    MessageBox.Show("Der Part konnte nicht gelöscht werden.\r\n\r\n");
            }
        }

        private void tree_Model_AfterLabelEdit(object sender, NodeLabelEditEventArgs e)
        {            
            int tag = Convert.ToInt32(tree_Model.SelectedNode.Tag);
            if (tag > 0)
            {
                UpdateNodeRow(tag, null, e.Label, null, null, null, null);
                txt_Name.Text = e.Label;
            }
        }

        private void txt_Name_Leave(object sender, EventArgs e)
        {
            int tag = Convert.ToInt32(tree_Model.SelectedNode.Tag);
            if (tag >= 0)
            {
                UpdateNodeRow(tag, null, txt_Name.Text, null, null, null, null);
                tree_Model.SelectedNode.Text = txt_Name.Text;
            }
        }

        /// <summary>
        /// Fügt einen Datensatz in die Node-Tabelle ein.
        /// </summary>
        /// <param name="name">Name des Knotens</param>
        /// <returns>Angelegte Id im Dataset</returns>
        private int InsertNodeRow(string name, string nodePath)
        {
            try
            {
                dataset_Main.NodeRow noderow = dataset_Main.Node.NewNodeRow();
                noderow.Name = name;
                noderow.Channel = "inline";
                noderow.NodePath = nodePath;
                dataset_Main.Node.Rows.Add(noderow);
                return noderow.Id;
            }
            catch (Exception)
            {
                return -1;
            }
        }

        /// <summary>
        /// Fügt einen Datensatz in die Node-Tabelle ein.
        /// </summary>
        /// <param name="name">Name des Knotens</param>
        /// <returns>Angelegte Id im Dataset</returns>
        private int InsertNodeRow(string name, int parentId, string nodePath)
        {
            try
            {
                dataset_Main.NodeRow noderow = dataset_Main.Node.NewNodeRow();
                noderow.Name = name;
                noderow.Channel = "inline";
                noderow.Parent_Id = parentId;
                noderow.NodePath = nodePath;
                dataset_Main.Node.Rows.Add(noderow);
                return noderow.Id;
            }
            catch (Exception)
            {
                return -1;
            }
        }

        /// <summary>
        /// Löscht eine Zeile aus der Node-Tabelle
        /// </summary>
        /// <param name="Node_Id">Id der zu löschenden Zeile</param>
        /// <returns></returns>
        private bool DeleteNodeRow(int Node_Id)
        {
            try
            {
                grid_Nodes.SelectionChanged -= grid_Nodes_SelectionChanged;
                dataset_Main.NodeRow row = dataset_Main.Node.Rows
                    .Cast<dataset_Main.NodeRow>()
                    .Where(r => r.Id == Node_Id)
                    .First();
                row.Delete();
                grid_Nodes.SelectionChanged += grid_Nodes_SelectionChanged;
            }
            catch (Exception)
            {
                return false;
            }
            return true;
        }

        private bool UpdateNodeRow(int Node_Id, int? parentId, string name, string channel, string format, string model, string nodePath)
        {
            try
            {
                dataset_Main.NodeRow row = dataset_Main.Node.Rows
                    .Cast<dataset_Main.NodeRow>()
                    .Where(r => r.Id == Node_Id)
                    .First();
                if (parentId.HasValue)
                    row.Parent_Id = parentId.Value;
                if (name != null)
                    row.Name = name;
                if (channel != null)
                    row.Channel = channel;
                if (format != null)
                    row.Format = format;
                if (model != null)
                    row.Model = model;
                if (nodePath != null)
                    row.NodePath = nodePath;
            }
            catch (Exception)
            {
                return false;
            }
            return true;
        }

        /// <summary>
        /// Gibt die Zeile des Node-Grids zurück.
        /// </summary>
        /// <param name="id">Node_Id</param>
        /// <returns></returns>
        private DataGridViewRow GetGridNodeRowById(int Node_Id)
        {
            DataGridViewRow row = grid_Nodes.Rows
                .Cast<DataGridViewRow>()
                .Where(r => (int)r.Cells["Node_Id"].Value == Node_Id)
                .First();

            return row;
        }

        private TreeNode GetNodeByNodeIndexPath(string indexPath)
        {
            string[] values = indexPath.Split(',');
            TreeNode result = null;

            result = tree_Model.TopNode;

            foreach (string value in values)
            {
                result = result.Nodes[Convert.ToInt32(value)];
            }
            //tree_Model.SelectedNode.
            return result;
        }

        private string GetNodeIndexPath(TreeNode node)
        {
            bool squareReached = false;
            string result = string.Empty;
            string sep = string.Empty;

            while (!squareReached)
            {
                result = node.Index.ToString() + sep + result;
                sep = ",";
                node = node.Parent;
                if (Convert.ToInt32(node.Tag) == 0)
                    squareReached = true;
            }

            return result;
        }

        private void tree_Model_AfterSelect(object sender, TreeViewEventArgs e)
        {
            //tree_Model.SelectedNode.BackColor = SystemColors.Highlight;
            //tree_Model.SelectedNode.ForeColor = SystemColors.HighlightText;

            txt_Name.Text = tree_Model.SelectedNode.Text;
            int id = Convert.ToInt32(tree_Model.SelectedNode.Tag);
            lbl_TagId.Text = id.ToString();
            lbl_NodeIndex.Text = tree_Model.SelectedNode.Index.ToString();
            if (id > 0)
            {
                grid_Nodes.SelectionChanged -= grid_Nodes_SelectionChanged;
                GetGridNodeRowById(id).Cells[0].Selected = true;
                grid_Nodes.SelectionChanged += grid_Nodes_SelectionChanged;
                DataView dataview = dataset_Main.Properties.DefaultView;
                dataview.RowFilter = "Node_Id = " + id.ToString();
                grid_Properties.DataSource = dataview;
                lbl_NodePath.Text = GetNodeIndexPath(tree_Model.SelectedNode);
            }
        }

        private void grid_Nodes_SelectionChanged(object sender, EventArgs e)
        {
            string nodepath = (string)grid_Nodes.CurrentRow.Cells["Node_NodePath"].Value;
            tree_Model.AfterSelect -= tree_Model_AfterSelect;
            tree_Model.SelectedNode = GetNodeByNodeIndexPath(nodepath);
            tree_Model.AfterSelect += tree_Model_AfterSelect;
        }

        private void tree_Model_BeforeSelect(object sender, TreeViewCancelEventArgs e)
        {
            //if (tree_Model.SelectedNode != null)
            //{
            //    tree_Model.SelectedNode.BackColor = SystemColors.Window;
            //    tree_Model.SelectedNode.ForeColor = SystemColors.WindowText;
            //}
        }

        private void tree_Model_Leave(object sender, EventArgs e)
        {
            //tree_Model.SelectedNode.BackColor = SystemColors.Highlight;
            //tree_Model.SelectedNode.ForeColor = SystemColors.HighlightText;
        }

        private void tree_Model_Enter(object sender, EventArgs e)
        {

            //tree_Model.SelectedNode.BackColor = SystemColors.Highlight;
        }

        private void UnderConstructionItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Die Funktion ist nocht nicht implementiert oder wird gerade bearbeitet.", "Under Construction", MessageBoxButtons.OK, MessageBoxIcon.Information); 
        }

        private void tree_Model_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            tree_Model.SelectedNode = e.Node;
        }
    }
}
