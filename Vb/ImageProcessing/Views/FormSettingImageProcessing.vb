Public Class FormSettingImageProcessing
    Public ReadOnly Property ComboBoxImageProcessingType() As System.Windows.Forms.ComboBox
        Get
            Return cmbBoxImageProcessingType
        End Get
    End Property

    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

        LoadParam()
    End Sub

    Public Sub LoadParam()
        Dim items = New List(Of ComImageProcessingType)
        items.Add(New ComImageProcessingType(My.Settings.ImgTypeEdgeId, My.Settings.ImgTypeEdgeName))
        items.Add(New ComImageProcessingType(My.Settings.ImgTypeGrayScaleId, My.Settings.ImgTypeGrayScaleName))
        items.Add(New ComImageProcessingType(My.Settings.ImgTypeBinarizationId, My.Settings.ImgTypeBinarizationName))
        items.Add(New ComImageProcessingType(My.Settings.ImgTypeGrayScale2DiffId, My.Settings.ImgTypeGrayScale2DiffName))
        items.Add(New ComImageProcessingType(My.Settings.ImgTypeColorReversalId, My.Settings.ImgTypeColorReversalName))

        cmbBoxImageProcessingType.Items.Add(My.Settings.ImgTypeEdgeName)
        cmbBoxImageProcessingType.Items.Add(My.Settings.ImgTypeGrayScaleName)
        cmbBoxImageProcessingType.Items.Add(My.Settings.ImgTypeBinarizationName)
        cmbBoxImageProcessingType.Items.Add(My.Settings.ImgTypeGrayScale2DiffName)
        cmbBoxImageProcessingType.Items.Add(My.Settings.ImgTypeColorReversalName)
        cmbBoxImageProcessingType.SelectedIndex = items.Find(Function(x) x.Name = My.Settings.ImgTypeSelectName)?.Id - 1

        Return
    End Sub

    Public Sub SaveParam()
        My.Settings.ImgTypeSelectName = cmbBoxImageProcessingType.SelectedItem.ToString()
        My.Settings.Save()

        Return
    End Sub

    Private Sub OnClickOk(sender As Object, e As EventArgs) Handles btnOk.Click
        SaveParam()
        Me.DialogResult = DialogResult.OK
        Close()
    End Sub

    Private Sub OnClickCancel(sender As Object, e As EventArgs) Handles btnCancel.Click
        Me.DialogResult = DialogResult.Cancel
        Close()
    End Sub
End Class